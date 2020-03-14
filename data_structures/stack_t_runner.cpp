#include <iostream>
#include "stack_t.h"

int main(void)
{
    stack_t<int> s;
    s.push(1); // 1
    s.push(2); // 2, 1
    s.push(3); // 3, 2, 1
    std::cout << s << "\n";
    s.pop(); // 2, 1
    std::cout << s << "\n";
    s.pop(); // 1
    std::cout << s << "\n";

    s.push(4); // 4, 1
    std::cout << s.peek() << "\n"; // 4
    std::cout << s.get(1) << "\n"; // 1
}

