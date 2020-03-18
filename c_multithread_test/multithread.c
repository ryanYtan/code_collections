#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include "cpu.h"
#include <sys/sysinfo.h>

struct thd
{
        long n;
};

void *multi_fn(void *args)
{
        struct thd *inf = args;
        long iter = inf->n;
        _function(iter);
        pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
        if (argc < 2) {
                fprintf(stderr, "Usage: %s ITERATIONS\n", argv[0]);
                exit(1);
        }

        long iter = strtol(argv[1], NULL, 10);
        int ncores = get_nprocs_conf();
        pthread_t *tids = malloc(ncores * sizeof(*tids));

        for (int i = 0; i < ncores; i++) {
                struct thd *info = malloc(sizeof(*info));
                info->n = iter / ncores;
                pthread_create(&tids[i], NULL, multi_fn, info);
        }

        for (int i = 0; i < ncores; i++) {
                pthread_join(tids[i], NULL);
        }
}
