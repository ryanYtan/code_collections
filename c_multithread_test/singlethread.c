#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cpu.h"
#define MU "μ"

int main(int argc, char *argv[])
{
        if (argc < 2) {
                fprintf(stderr, "Usage: %s ITERATIONS\n", argv[0]);
                exit(1);
        }

        long iter = strtol(argv[1], NULL, 10);

        clock_t begin = clock();
        _function(iter);
        clock_t end = clock();
        double time = (double)(end - begin) / CLOCKS_PER_SEC;

        printf("%.2lf %ss for %ld iterations\n", time, "", iter);
}
