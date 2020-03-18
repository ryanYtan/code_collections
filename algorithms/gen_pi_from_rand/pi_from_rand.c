#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

typedef unsigned long long ull;
const double EPSILON = 0.0000000001;

double gen_rand()
{
        return (double)random() / RAND_MAX;
}

double dist_from_origin(double x, double y)
{
        return sqrt(x*x + y*y);
}

int main()
{
        struct timespec ts;
        timespec_get(&ts, TIME_UTC);
        srandom(ts.tv_nsec ^ ts.tv_sec);

        ull tries = 0;
        ull inside = 0;
        double estimate = 0;

        while (fabs(M_PI - estimate) > EPSILON) {
                tries++;
                double x = gen_rand();
                double y = gen_rand();

                if (dist_from_origin(x, y) <= 1.0f)
                        inside++;

                estimate = ((double)inside / tries) * 4.0f;

                printf("[%llu][est] %.10lf\r", tries, estimate);
        }

        printf("result = %.15lf\n", estimate);
}
