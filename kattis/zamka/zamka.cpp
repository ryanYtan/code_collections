#include <iostream>
#include <limits>

int sum_digits(int n)
{
        int sum = 0;
        while (n > 0) {
                int digit = n % 10;
                sum += digit;
                n /= 10;
        }
        return sum;
}

int main()
{
        int l, d, x;
        std::cin >> l >> d >> x;

        int n = std::numeric_limits<int>::max();
        int m = std::numeric_limits<int>::min();

        // find n
        for (int i = l; i <= d; i++) {
                int sum = sum_digits(i);
                if (i < n && sum == x)
                        n = i;
                if (i > m && sum == x)
                        m = i;
        }

        std::cout << n << "\n";
        std::cout << m << "\n";
}
