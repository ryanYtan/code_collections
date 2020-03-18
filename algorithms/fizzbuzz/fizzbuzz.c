#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
        FILE* fptr = fopen("results.txt", "w");
        if (fptr == NULL) {
                fprintf(stderr, "%s: could not open file\n", argv[0]);
                exit(1);
        }

        const int BUFSIZE = 256;
        const long UNTIL = 1e6;
        const char* const FIZZ = "Fizz";
        const char* const BUZZ = "Buzz";

        for (long i = 1; i <= UNTIL; i++) {
                char buf[BUFSIZE] = {0};

                if (i % 3 == 0) {
                        strcat(buf, FIZZ);
                }
                if (i % 5 == 0) {
                        strcat(buf, BUZZ);
                }

                if (buf[0] == 0) {
                        fprintf(fptr, "%ld\n", i);
                } else {
                        fprintf(fptr, "%s\n", buf);
                }
        }

        fclose(fptr);
}
