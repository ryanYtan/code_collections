/**
 * c_io.c
 *
 * Based on Prof. Ooi Wei Tsang's solution from the CS1010
 * I/O Library
 *
 * https://github.com/nus-cs1010-1819-s1/libcs1010
 */
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_io.h"

const int BUFSIZE_T = 32
const int BASE = 10

/**
 * remove_spaces() - Removes leading whitespace from stdin.
 *
 * Return: int value of first non-whitespace non-EOF character,
 *         or EOF if EOF is reached.
 */
static int remove_spaces()
{
        int c;
        while ((c = fgetc(stdin)) && isspace(c) && c != EOF);
        return c;
}

/**
 * fill_buffer() - Reads characters from stdin into the given buffer.
 * @buf:        buffer to be read into.
 * @bufsize:    number of characters to read.
 *
 * Reads characters from stdin into the given buffer. The maximum
 * number of characters that can be read is equal to bufsize.
 *
 * Return: Number of characters read into the given buffer.
 */
static int fill_buffer(char *buf, int bufsize)
{
        int i = 0;
        int c;

        while (i < bufsize && (c = fgetc(stdin)) && c != EOF && !isspace(c))
                buf[i++] = c;

        if (c == EOF || isspace(c))
                buf[i++] = '\0';

        return i;
}

/**
 * read_word() - Reads an arbitrary number of non-whitespace
 *               characters from stdin.
 *
 * The caller is responsible for freeing the allocated memory returned
 * by this function.
 *
 * Return: Pointer to the first character, or NULL if an error occurs.
 */
char *read_word()
{
        int c = remove_spaces();
        if (c == EOF)
                return NULL;

        char *ret = malloc(1);
        *ret = c;
        char buf[BUFSIZE_T];
        int buf_len;
        int total_len = 1; /* number of elements in ret excluding '\0' */

        do {
                buf_len = fill_buffer(buf, BUFSIZE_T);
                char *tmp = realloc(ret, total_len + buf_len + 1);
                if (tmp == NULL) {
                        free(ret);
                        return NULL;
                }
                ret = tmp;
                memcpy(ret + total_len, buf, buf_len);
                total_len += buf_len;
        } while (buf_len == BUFSIZE_T && buf[buf_len - 1] != '\0');
        return ret;
}

/**
 * read_line() - Reads a line of arbitrary length from stdin.
 *
 * Return: Pointer to the first character, or NULL if an error occurs.
 */
char *read_line()
{
        char *ret = NULL;
        size_t unused = 0;
        errno = 0;
        if ((getline(&ret, &unused, stdin) == -1) && errno == ENOMEM) {
                free(ret);
                return NULL;
        }
        ret[strcspn(ret, "\n")] = '\0'; /* remove newline from buffer */
        return ret;
}

/**
 * read_long() - Reads a long int from stdin.
 * @result:     Result to return
 *
 * Reads a long int from stdin.
 *
 * Return value will be:
 * - IOE_SUCCESS if the given string is successfully converted.
 * - IOE_FAILURE if a general I/O error occurs.
 * - IOE_INVAL if the input is invalid
 * - IOE_RANGE if the given number is outside the range of long
 *
 * The function does not guarantee the value of *result if
 * the returned value is not IOE_SUCCESS. The function will
 * consume any non-numerical character before the start of the
 * given input, and one character at the end of the input.
 *
 * Return: The given number if conversion is successful.
 */
static int read_long_err(char *nptr, char *endptr, long ret)
{
        if (nptr == endptr || '\0' != *endptr)
                return IOE_INVAL;
        else if (ERANGE == errno && (ret == LONG_MAX || ret == LONG_MIN))
                return IOE_RANGE;
        else if (0 != errno && 0 == ret)
                return IOE_FAILURE;
        else
                return IOE_SUCCESS;
}
int read_long(long *result)
{
        int ret;
        char *nptr = read_word();

        if (nptr == NULL)
                return IOE_FAILURE;

        errno = 0;
        char *endptr;
        *result = strtol(nptr, &endptr, BASE);
        ret = read_long_err(nptr, endptr, *result);
        free(nptr);
        return ret;
}

/**
 * read_int() - Reads an int from stdin.
 * @result:     Result to return
 *
 * Reads an int from stdin.
 *
 * Return value will be:
 * - IOE_SUCCESS if the given string is successfully converted.
 * - IOE_FAILURE if a general I/O error occurs.
 * - IOE_INVAL if the input is invalid
 * - IOE_RANGE if the given number is outside the range of int
 *
 * The function does not guarantee the value of *result if
 * the returned value is not IOE_SUCCESS. The function will
 * consume any non-numerical character before the start of the
 * given input, and one character at the end of the input.
 *
 * Return: The given number if conversion is successful.
 */
int read_int(int *result)
{
        long tmp;
        int ret = read_long(&tmp);
        if (ret == 0 && (tmp < INT_MIN || INT_MAX < tmp))
                ret = IOE_RANGE;
        *result = (int)tmp;
        return ret;
}

/**
 * read_double() - Reads a double from stdin.
 * @result         Result to return
 *
 * Reads a double from stdin.
 */
static int read_dbl_err(char *nptr, char *endptr, long val)
{
        if (ERANGE == errno)
                return IOE_RANGE;
        else if (nptr == endptr || '\0' != *endptr)
                return IOE_INVAL;
        else if (ERANGE == errno && (val == LONG_MAX || val == LONG_MIN))
                return IOE_RANGE;
        else if (0 != errno && 0 == val)
                return IOE_FAILURE;
        else
                return IOE_SUCCESS;
}
int read_double(double *result)
{
        int ret;
        char *ptr = read_word();
        if (ptr == NULL)
                return IOE_FAILURE;

        errno = 0;
        char *endptr;
        *result = strtod(ptr, &endptr);
        ret = read_dbl_err(ptr, endptr, *result);
        free(ptr);
        return ret;
}
