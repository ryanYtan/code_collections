#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define SEMIPRIME 0
#define PRIME 1
#define NEITHER 2

// O(sqrt(n))
bool is_prime(long n)
{
    if (n <= 1) return false;
    if (n <= 3) return true;
    long until = sqrt(n);
    for (long i = 2; i <= until; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int is_prime_or_semiprime(long n) {
    if (n <= 1) return NEITHER;
    if (n <= 3) return PRIME;
    long until = sqrt(n);
    for (long i = 2; i <= until; i++) {
        if (n % i == 0) {
            if (is_prime(i) && is_prime(n / i)) {
                return SEMIPRIME;
            }
            return NEITHER;
        }
    }
    return PRIME;
}

int main()
{
    long n;
    scanf("%ld", &n);

    long total = 0;
    for (long i = 2; i <= n / 2; i++) {
        long p1 = is_prime_or_semiprime(i);
        if (p1 == PRIME || p1 == SEMIPRIME) {
            long j = n - i;
            long p2 = is_prime_or_semiprime(j);
            if ((p1 == PRIME && p2 == SEMIPRIME) || (p1 == SEMIPRIME && p2 == PRIME)) {
                total++;
            }
        }
    }

    printf("%ld\n", total);
}
