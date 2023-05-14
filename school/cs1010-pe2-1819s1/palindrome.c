#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool is_palindrome(int n, char *s, int i, int j)
{
    if (i > j) {
        return true;
    }
    if (s[i] < 'a' || 'z' < s[i]) {
        return is_palindrome(n, s, i + 1, j);
    }
    if (s[j] < 'a' || 'z' < s[j]) {
        return is_palindrome(n, s, i, j - 1);
    }
    return s[i] == s[j] && is_palindrome(n, s, i + 1, j - 1);
}

int main()
{
    char *s = NULL;
    size_t bufsize = 0;
    getline(&s, &bufsize, stdin);

    //remove newline from buffer
    s[strcspn(s, "\n")] = '\0';
    bufsize--;

    for (long i = 0; i < bufsize; i++) {
        s[i] = tolower(s[i]);
    }

    if (is_palindrome(bufsize, s, 0, bufsize - 1)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    free(s);
}
