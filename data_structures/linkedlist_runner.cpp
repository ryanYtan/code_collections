#include <iostream>
#include "linkedlist.h"

int main(void)
{
    linkedlist<int> l;
    l.insert(1, 0); // 1
    l.insert(2, 0); // 2, 1
    l.insert(3, 0); // 3, 2, 1
    l.insert(4, 1); // 3, 4, 2, 1
    l.insert(5, 2); // 3, 4, 5, 2, 1
    l.insert(6, 5); // 3, 4, 5, 2, 1, 6

    std::cout << l.get(0) << "\n"; // 3
    std::cout << l.get(3) << "\n"; // 2
    std::cout << l.get(5) << "\n"; // 6
    std::cout << l.get_first() << "\n"; // 3
    std::cout << l.get_last() << "\n"; // 6

    l.remove(0); // 4, 5, 2, 1, 6
    std::cout << l << "\n";

    l.remove(2); // 4, 5, 1, 6
    std::cout << l << "\n";

    l.remove(3); // 4, 5, 1
    std::cout << l << "\n";
    l.remove(0); // 5, 1
    std::cout << l << "\n";
    l.remove(0); // 1
    std::cout << l << "\n";
    l.remove(0); // []
    std::cout << l << "\n";

    std::cout << l.empty() << "\n"; // true

    l.insert(10, 0); // 10
    std::cout << l << "\n";
    std::cout << l.empty() << "\n"; // false

    l.insert_first(5); // 5, 10
    l.insert_last(15); // 5, 10, 15
    std::cout << l << "\n";

    l.remove_first(); // 10, 15
    l.remove_last();  // 10
    std::cout << l << "\n";
}
