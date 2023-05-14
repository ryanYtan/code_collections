#include <stdio.h>
#include <math.h>

double EPSILON = 0.000000001;

double f(double a, double b, double c, double d, double x)
{
        return a*x*x*x + b*x*x + c*x + d;
}

double df(double a, double b, double c, double x)
{
        return 3.0*a*x*x + 2.0*b*x + c;
}

double newton_it(double a, double b, double c, double d, double xi)
{
        return xi - (f(a, b, c, d, xi) / df(a, b, c, xi));
}

int main()
{
        double a, b, c, d;
        double xn;
        scanf("%lf %lf %lf %lf %lf", &a, &b, &c, &d, &xn);

        double xnp1;
        while (1) {
                xnp1 = newton_it(a, b, c, d, xn);
                if (fabs(xnp1 - xn) < EPSILON) {
                        break;
                }
                xn = xnp1;
        }

        printf("%.4lf\n", xnp1);
}
