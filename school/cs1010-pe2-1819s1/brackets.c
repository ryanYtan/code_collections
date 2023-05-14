#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_open(char c)
{
    return c == '(' || c == '{' || c == '<' || c == '[';
}

bool is_match(char c, char d)
{
    return (c == '(' && d == ')')
            || (c == '{' && d == '}')
            || (c == '<' && d == '>')
            || (c == '[' && d == ']');
}

long consume(char *s, long n, long i)
{
    if (i == n) {
        return n;
    }
    if (!is_open(s[i])) {
        return i;
    }
    long end = consume(s, n, i + 1);
    if (is_match(s[i], s[end])) {
        return consume(s, n, end + 1);
    }
    return i;
}

int main()
{
    char *s = NULL;
    size_t bufsize;
    getline(&s, &bufsize, stdin);
    s[strcspn(s, "\n")] = '\0';
    size_t n = strlen(s);

    long end = consume(s, n, 0);
    if (end == n) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
}
