#include "cstr.h"
#include <stdlib.h>
#include <string.h>
#define _CSTR_BUFLEN 32

static
cstr *_cstralloc()
{
        return malloc(sizeof(cstr));
}

static
cstr *_cstr_n_init_empty(cstr *empty, const char *init, size_t len)
{
        char *str = malloc(len + 1);
        if (str == NULL) {
                return NULL;
        }
        memcpy(empty, init, len + 1);
        empty->len = len;
        return empty;
}

static
void *_copy(const void *s, size_t memsize)
{
        void *copy = malloc(memsize);
        if (copy == NULL && memsize != 0) {
                return NULL;
        }
        memcpy(copy, s, memsize);
        return copy;
}

cstr *cstrnnew(const char *init, size_t len)
{
        cstr *ret = _cstralloc();
        if (ret == NULL)
                return NULL;

        ret->len = len;
        ret->str = _copy(init, len + 1);
        if (ret->str == NULL) {
                free(ret);
                return NULL;
        }

        return ret;
}

cstr *cstrnew(const char *init)
{
        size_t len = strlen(init);
        return cstrnnew(init, len);
}

cstr *cstrempty()
{
        cstr *empty = _cstralloc();

        if (empty == NULL) {
                return NULL;
        }

        empty->len = 0;
        empty->str = NULL;
        return empty;
}

cstr *cstrdup(const cstr *src)
{
        return cstrnnew(src->str, src->len);
}

void cstrdelete(cstr *s)
{
        free(s->str);
        free(s);
}

void cstradelete(cstr **s_arr)
{
        size_t i = 0;
        while (s_arr[i] != NULL) {
                cstrdelete(s_arr[i]);
                i++;
        }
        free(s_arr[i]); // cstr* pointing to NULL
        free(s_arr);
}

char cstr_at(const cstr *s, size_t index)
{
        return s->str[index];
}

bool cstr_isempty(const cstr *s)
{
        return s->str == NULL && s->len == 0;
}

size_t cstrlen(const cstr *s)
{
        return s->len;
}

char *cstrtostr(const cstr *s)
{
        return s->str;
}

cstr *cstrncat(cstr *s, const char *append, size_t append_len)
{
        if (cstr_isempty(s)) {
                cstr *cs = _cstr_n_init_empty(s, append, append_len);
                return cs == NULL ? NULL : cs;
        }

        char *tmp = realloc(s->str, s->len + append_len + 1);
        if (tmp == NULL)
                return NULL;
        memcpy(tmp + s->len, append, append_len + 1);
        s->str = tmp;
        s->len += append_len;
        return s;
}

cstr *cstrcat(cstr *s, const char *append)
{
        size_t len = strlen(append);
        return cstrncat(s, append, len);
}

cstr *cstrncstrcat(cstr *s, const cstr *append)
{
        return cstrncat(s, append->str, append->len);
}

cstr **cstrtok(const char *s, const char* const delim, size_t *n_tokens)
{
       cstr *tmp = cstrnew(s);
       cstr **ret = cstrtokcstr(tmp, delim, n_tokens);
       free(tmp);
       return ret;
}

cstr **cstrtokcstr(const cstr *s, const char* const delim, size_t *n_tokens)
{
        char *copy = _copy(s->str, s->len + 1);
        if (copy == NULL)
                goto retnull;

        cstr **ret = malloc(sizeof(cstr*));
        size_t retidx = 0;
        size_t retlen = 1;
        if (ret == NULL)
                goto freecopy;

        char *tok = strtok(copy, delim);
        while (tok) {
                cstr *cs = cstrnew(tok);
                if (cs == NULL)
                        goto freeret_recursive;

                if (retidx == retlen) {
                        cstr **tmp = realloc(ret, retlen * 2 * sizeof(cstr*));
                        retlen *= 2;
                        if (tmp == NULL)
                                goto freeret_recursive;
                        ret = tmp;
                }
                ret[retidx] = cs;
                retidx++;

                tok = strtok(NULL, delim);
        }

        cstr **resize = realloc(ret, (retidx + 1) * sizeof(cstr*));
        if (resize == NULL)
                goto freeret_recursive;
        ret = resize;

        ret[retidx] = NULL;
        if (n_tokens != NULL)
                *n_tokens = retidx;
        goto out;

freeret_recursive:
        for (size_t i = 0; i < retidx; i++) {
                cstrdelete(ret[i]);
        }
        free(ret);
freecopy:
        free(copy);
retnull:
        return NULL;
out:
        free(copy);
        return ret;
}

cstr *cstrjoin(const char *const *const argv, int argc, const char *delim)
{
        if (argc <= 0)
                return NULL;

        size_t delimlen = strlen(delim);

        cstr *ret = cstrnew(argv[0]);
        if (ret == NULL)
                goto fail;

        cstr *err;
        for (int i = 1; i < argc; i++) {
                err = cstrcat(ret, delim);
                if (err == NULL)
                        goto freeret;

                err = cstrcat(ret, argv[i]);
                if (err == NULL)
                        goto freeret;
        }

        return ret;

freeret:
        cstrdelete(ret);
fail:
        return NULL;
}
