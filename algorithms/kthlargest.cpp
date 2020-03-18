/**
 * @file: kthlargest.cpp
 */
#include <iostream>
#include <queue>
#include <algorithm>
#include <stdlib.h>

constexpr auto LEN = 10;
constexpr auto K = 4;
std::vector<int> a({123, 613, 473, 572, 234, 665, 453, 176, 565, 323});
std::vector<int> b({123, 613, 473, 572, 234, 665, 453, 176, 565, 323});
std::vector<int> c({123, 613, 473, 572, 234, 665, 453, 176, 565, 323});
std::vector<int> d({123, 613, 473, 572, 234, 665, 453, 176, 565, 323});

void printarray(int arr[]) {
    for (int i = 0 ; i < LEN; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

/**
 * First Method:
 * Run Bubble Sort k times, return a[LEN - k]
 * Complexity: O(nk)
 */
int k_bubble_sort() {
    int counter = 0;
    while (counter < K) {
        for (int i = 0; i < LEN - 1; i++) {
            if (a[i + 1] < a[i]) {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
        counter++;
    }
    return a[LEN - K];
}

/**
 * Second Method:
 * Sort in O(nlogn), return a[LEN - k]
 * Complexity: O(nlogn)
 */
int sort_to_k() {
    std::sort(b.begin(), b.end());
    return b[LEN - K];
}

/**
 * Third Method:
 * Use a Max Heap, call extractMax() k times
 * Complexity: O(n + klogn)
 */
int slow_heap_k() {
    std::priority_queue<int> q;
    for (auto i : c) {
        q.push(i);
    }
    for (auto i = 0; i < K - 1; i++) {
        q.pop();
    }
    return q.top();
}

/**
 * Fourth Method:
 * Use a Min Heap, heapify first k elements, then compare the rest of the
 * elements with root of heap. If element is larger than root, pop the root
 * and insert the new element.
 * Complexity: O(k + (n - k)log k)
 */
int fast_heap_k() {
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    for (int i = 0; i < K; i++) {
        q.push(d[i]);
    }

    for (int i = K; i < LEN; i++) {
        int top = q.top();
        if (d[i] > top) {
            q.push(d[i]);
            q.pop();
        }
    }
    return q.top();
}


int main() {
    std::cout << k_bubble_sort() << '\n';
    std::cout << sort_to_k() << '\n';
    std::cout << slow_heap_k() << '\n';
    std::cout << fast_heap_k() << '\n';
}
