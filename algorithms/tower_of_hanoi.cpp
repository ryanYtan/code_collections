#include <iostream>
#include <vector>

void move(int disc_num, int src, int dst)
{
    std::cout << "Disc " << disc_num << ": Peg " << src << " -> Peg " << dst << "\n";
}

void tower_of_hanoi(int n_discs, int src, int dst, int tmp)
{
    if (n_discs == 1) {
        move(n_discs, src, dst);
    } else {
        tower_of_hanoi(n_discs - 1, src, tmp, dst);
        move(n_discs, src, dst);
        tower_of_hanoi(n_discs - 1, tmp, dst, src);
    }
}

int main()
{
    tower_of_hanoi(4, 1, 3, 2);
}
