#include <stdio.h>
#include <stdlib.h>

void transpose_matrix(double **m1, double **m2, long nrows, long ncols)
{
    for (long i = 0; i < nrows; i++) {
        for (long j = 0; j < ncols; j++) {
            m2[j][i] = m1[i][j];
        }
    }
}

int main()
{
    long m, n;
    scanf("%ld %ld", &m, &n);

    double **m1 = calloc(m, sizeof(*m1));
    for (long i = 0; i < m; i++) {
        m1[i] = calloc(n, sizeof(**m1));
        for (long j = 0; j < n; j++) {
            scanf("%lf", &m1[i][j]);
        }
    }

    double **m2 = calloc(n, sizeof(*m2));
    for (long i = 0; i < n; i++) {
        m2[i] = calloc(m, sizeof(**m2));
    }

    transpose_matrix(m1, m2, m, n);

    for (long i = 0; i < n; i++) {
        for (long j = 0; j < m; j++) {
            if (j == 0) {
                printf("%.4lf", m2[i][j]);
            } else {
                printf(" %.4lf", m2[i][j]);
            }
        }
        printf("\n");
    }

    for (long i = 0; i < m; i++) {
        free(m1[i]);
    }
    free(m1)
    for (long i = 0; i < n; i++) {
        free(m2[i]);
    }
    free(m2)
}
