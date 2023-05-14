#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(long n)
{
        if (n <= 1) {
                return false;
        }
        if (n <= 3) {
                return true;
        }
        long until = sqrt(n);
        for (long i = 2; i <= until; i += 1) {
                if (n % i == 0) {
                        return false;
                }
        }
        return true;
}

int main()
{
        long n;
        scanf("%ld", &n);

        long total = 0;
        for (long i = 2; i <= (long)(n / 2); i += 1) {
                long a = i;
                long b = n - i;
                if (is_prime(a) && is_prime(b)) {
                        total += 1;
                }
        }

        printf("%ld\n", total);
}
