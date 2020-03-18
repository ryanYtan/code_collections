#include <iostream>
#include <math.h>
#include <iomanip>

constexpr auto EPSILON = 0.00000001;

double f(double a, double b, double c, double d, double x) {
    return a*x*x*x + b*x*x + c*x + d;
}

double fprime(double a, double b, double c, double x) {
    return 3.0*a*x*x + 2.0*b*x + c;
}

double find_root(double a, double b, double c, double d, double x) {
    double fx = f(a,b,c,d,x);
    if (fabs(fx) < EPSILON) {
        return x;
    }
    return find_root(a,b,c,d, x - f(a,b,c,d,x) / fprime(a,b,c,x));
}

int main() {
    double a, b, c, d, x;
    std::cin >> a >> b >> c >> d >> x;
    std::cout << std::setprecision(5) << find_root(a,b,c,d,x) << '\n';
}
