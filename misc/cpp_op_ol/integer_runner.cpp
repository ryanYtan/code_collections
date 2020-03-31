#include <iostream>
#include "integer.h"

int main()
{
    integer i, j;
    std::cin >> i >> j;

    std::cout << "i = " << i << " | j = " << j << "\n";

    std::cout << "i + j:  " << i + j << "\n";
    std::cout << "i - j:  " << i - j << "\n";

    i += 1;
    std::cout << "i += 1: " << i << "\n";

    j += 2;
    std::cout << "j += 2: " << j << "\n";

    i++;
    std::cout << "i++:    " << i << "\n";
    std::cout << "--i:    " << --i << "\n";

    std::cout << "i < j:  " << std::to_string(i < j) << "\n";
    std::cout << "i <= j: " << std::to_string(i <= j) << "\n";
    std::cout << "i > j:  " << std::to_string(i > j) << "\n";
    std::cout << "i >= j: " << std::to_string(i >= j) << "\n";
}
