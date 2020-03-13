#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define BUFSIZE 1024
#define BAD_CHARSEQ "gkmqvwxzio"

/* Returns true if any characters in charseq appear in cmp */
bool in(char *charseq, char *cmp)
{
        return strcspn(cmp, charseq) != strlen(cmp);
}

/* Returns a deep copy of to_cpy */
char *cpy(char *to_cpy)
{
        char *ret = malloc(strlen(to_cpy) + 1);
        strcpy(ret, to_cpy);
        return ret;
}

/* reads a line from given stream */
size_t read_line(char **line, FILE *stream)
{
        if (*line) {
                free(*line);
                *line = NULL;
        }
        char buf[BUFSIZE];
        size_t n = 0;
        int c;
        while ((c = fgetc(stream)) != EOF && c != '\n') {
                buf[n] = c;
                n++;
        }
        if (c == EOF)
                return -1;

        buf[n] = '\0';

        char *tmp = malloc(n + 1);
        memcpy(tmp, buf, n + 1);
        *line = tmp;
        return n;
}

int main(int argc, char *argv[])
{
        if (argc < 2)
                goto usage;
        FILE *fp = NULL;
        if ((fp = fopen(argv[1], "r")) == NULL)
                goto usage;
        char *bad_char = BAD_CHARSEQ;

        char *line = NULL;
        size_t len;
        ssize_t read_len;

        char *lline = NULL;
        size_t lline_len = 0;

        while ((read_len = read_line(&line, fp)) != -1) {
                if (read_len > lline_len && !in(bad_char, line)) {
                        free(lline);
                        lline_len = read_len;
                        lline = cpy(line);
                }
        }
        printf("%s\n", lline);

        fclose(fp);
        free(line);
        free(lline);
        return 0;

usage:
        fprintf(stderr, "Usage: %s <PATH_TO_FILE>\n", argv[0]);
        return 1;
}
