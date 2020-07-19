#include "../lib_io/io.h"
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "selection_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "radix_lsd_sort.h"

template<typename T>
std::vector<T> copy(std::vector<T> &from)
{
    std::vector<T> to;
    std::copy(from.begin(), from.end(), std::back_inserter(to));
    return to;
}

int main(void)
{
    int num_values = read<int>();
    std::vector<int> arr = read_vector<int>(num_values);

    std::cout << "Array: " << vector_tostr(arr) << std::endl;
    std::vector<int> original = copy(arr);

    bubble_sort(arr);
    std::cout << "Using Bubble Sort: " << vector_tostr(arr) << std::endl;
    arr = copy(original);

    insertion_sort(arr);
    std::cout << "Using Insertion Sort: " << vector_tostr(arr) << std::endl;
    arr = copy(original);

    selection_sort(arr);
    std::cout << "Using Selection Sort: " << vector_tostr(arr) << std::endl;
    arr = copy(original);

    merge_sort(arr);
    std::cout << "Using Merge Sort: " << vector_tostr(arr) << std::endl;
    arr = copy(original);

    merge_sort(arr);
    std::cout << "Using Quick Sort: " << vector_tostr(arr) << std::endl;
    arr = copy(original);

    radix_lsd_sort(arr);
    std::cout << "Using Radix LSD Sort: " << vector_tostr(arr) << std::endl;
    arr = copy(original);
}
