#include <iostream>
#include "queue_t.h"

int main(void)
{
    queue_t<int> q;
    q.enqueue(1); // 1
    q.enqueue(2); // 1, 2
    q.enqueue(3); // 1, 2, 3
    std::cout << q << "\n";
    q.dequeue(); // 2, 3
    std::cout << q << "\n";
    q.dequeue(); // 3
    std::cout << q << "\n";

    q.enqueue(4); // 3, 4
    std::cout << q.peek() << "\n"; // 3
    std::cout << q.get(1) << "\n"; // 4
}

