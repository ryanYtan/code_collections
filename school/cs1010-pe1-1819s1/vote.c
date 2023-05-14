#include <stdio.h>

int main()
{
        long a;
        long b;
        scanf("%ld %ld", &a, &b);

        long total = a + b;

        double ap = (double)a / (double)total * 100.0;
        double bp = (double)b / (double)total * 100.0;

        printf("%.4lf %.4lf\n", ap, bp);
}
