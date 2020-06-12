#include "bitmask.hpp"
#include <iostream>
#include <sstream>

int main()
{
    Bits64 tester = 0b00000010;
    std::cout << as_str(tester) << "\n";

    tester = set(tester, 0);    //00000011
    std::cout << as_str(tester) << "\n";

    tester = set(tester, 0);    //00000011
    std::cout << as_str(tester) << "\n";

    tester = set(tester, 3, 7); //01111011
    std::cout << as_str(tester) << "\n";

    tester = set(tester, 3, 8); //11111011
    std::cout << as_str(tester) << "\n";

    tester = clear(tester, 0);  //11111010
    std::cout << as_str(tester) << "\n";

    tester = clear(tester, 4);  //11101010
    std::cout << as_str(tester) << "\n";

    tester = clear(tester, 5, 7);   // 10001010
    std::cout << as_str(tester) << "\n";

    tester = clear(tester, 3, 8);   // 00000010
    std::cout << as_str(tester) << "\n";

    tester = toggle(tester, 0); // 00000011
    std::cout << as_str(tester) << "\n";

    tester = toggle(tester, 0); // 00000010
    std::cout << as_str(tester) << "\n";

    tester = toggle(tester, 0, 4); // 00001101
    std::cout << as_str(tester) << "\n";

    std::cout << is_set(tester, 0) << "\n"; // 1
    std::cout << is_set(tester, 1) << "\n"; // 0
    std::cout << is_set(tester, 2) << "\n"; // 1
    std::cout << is_set(tester, 3) << "\n"; // 1
    std::cout << is_set(tester, 4) << "\n"; // 0

    std::cout << is_set(tester, 0, 4) << "\n"; // 0
    std::cout << is_set(tester, 2, 4) << "\n"; // 1
    std::cout << is_set(tester, 0, 0) << "\n"; // 1
    std::cout << is_set(tester, 0, 1) << "\n"; // 1
}
