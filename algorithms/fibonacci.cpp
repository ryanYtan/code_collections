/**
 * Define F(0) = 1, F(1) = 1, F(n) = F(n - 1) + F(n - 2)
 */
#include <iostream>
#include <vector>

int memo_fib(int n, std::vector<int>& memotable)
{
    if (n == 0 || n == 1)
        return 1;

    if (memotable[n] == -1) {
        memotable[n] = memo_fib(n - 1, memotable) + memo_fib(n - 2, memotable);
    }
    return memotable[n];
}

int naive_fib(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return naive_fib(n - 1) + naive_fib(n - 2);
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> memotable(n + 1, -1);
    std::cout << memo_fib(n, memotable) << "\n";
}
