#ifndef LIB_CSTR_INCLUDED
#define LIB_CSTR_INCLUDED
#include <stddef.h>
#include <stdbool.h>

typedef
        struct cstr_type
        {
                size_t len;
                char *str;
        }
cstr;

cstr *cstrnnew(const char *init, size_t len);
cstr *cstrnew(const char *init);
cstr *cstrempty();
cstr *cstrdup(const cstr *src);
void cstradelete(cstr **s_arr);
void cstrdelete(cstr *s);

char cstr_at(const cstr *s, size_t index);
bool cstr_isempty(const cstr *s);
size_t cstrlen(const cstr *s);
char *cstrtostr(const cstr *s);

cstr *cstrncat(cstr *s, const char *append, size_t append_len);
cstr *cstrcat(cstr *s, const char *append);
cstr *cstrncstrcat(cstr *s, const cstr *append);

cstr **cstrtokcstr(const cstr *s, const char* const delim, size_t *ntokens);
cstr **cstrtok(const char* s, const char* const delim, size_t *n_tokens);

cstr *cstrjoin(const char *const *const argv, int argc, const char *delim);
cstr *cstrjoincstr(const cstr *const *const argv, int argc, const char *delim);

#endif
