#include <iostream>
#include "point.h"

int main(void)
{
    point p1;
    point p2;
    std::cin >> p1;
    std::cin >> p2;
    std::cout << "p1: " << p1 << "\n";
    std::cout << "p2: " << p2 << "\n";
    std::cout << "p1.len(): " << p1.len() << "\n";
    std::cout << "p1.len(): " << p2.len() << "\n";
    std::cout << p1 + p2 << "\n";
    std::cout << p1 - p2 << "\n";
    std::cout << ++p2 << "\n";
    std::cout << --p2 << "\n";
    std::cout << " < " << std::to_string(p1 < p2)  << "\n";
    std::cout << " > " << std::to_string(p1 > p2)  << "\n";
    std::cout << "== " << std::to_string(p1 == p2) << "\n";
    std::cout << "!= " << std::to_string(p1 != p2) << "\n";
    std::cout << "<= " << std::to_string(p1 <= p2) << "\n";
    std::cout << ">= " << std::to_string(p1 >= p2) << "\n";
}
