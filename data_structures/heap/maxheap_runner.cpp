#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include "maxheap.h"
#include "../../lib_io/io.h"

constexpr auto vsize = 20;

int main(void)
{
    maxheap<int> h;
    std::mt19937 rng(std::chrono::steady_clock::now()
        .time_since_epoch()
        .count());

    std::vector<int> perm(vsize);
    for (int i = 0; i < vsize; i++)
        perm[i] = i + 1;
    std::shuffle(perm.begin(), perm.end(), rng);

    for (int i = 0; i < vsize; i++) {
        h.push(perm[i]);
    }

    std::cout << "perm: " << vector_tostr(perm) << "\n";

    if (!h.empty()) {
        std::cout << "[" << h.extract_max();
    }
    while (!h.empty()) {
        std::cout << ", " << h.extract_max();
    }
    std::cout << "]\n";
}
