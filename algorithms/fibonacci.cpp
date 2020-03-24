/**
 * Fibonacci Sequence follows:
 *    0,    1,    1,    2, 3, 5, 8, etc
 *    0th   1st   2nd   etc...
 */
#include <iostream>

using ull = unsigned long long;

ull dp_fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    ull memo[n + 1];
    memo[0] = 0;
    memo[1] = 1;

    for (int i = 2; i <= n; i++) {
        memo[i] = memo[i - 1] + memo[i - 2];
        if (memo[i] < memo[i - 1]) {
            std::cerr << "Unsigned overflow occured. Exiting...\n";
            exit(1);
        }
    }

    return memo[n];
}

ull naive_fib(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 1;
    return naive_fib(n - 1) + naive_fib(n - 2);
}

int main(void)
{
    int n;
    std::cin >> n;
    std::cout << dp_fib(n) << "\n";
}
