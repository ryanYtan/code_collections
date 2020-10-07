#include <iostream>
#include <vector>
#include <sstream>
#include "helper.h"

template<class T>
int partition(std::vector<T>& v, int left, int right)
{
    int pivot = v[right];
    int i = left;
    for (int j = left; j <= right; j++) {
        if (v[j] < pivot) {
            std::swap(v[i], v[j]);
            i++;
        }
    }
    std::swap(v[i], v[right]);
    return i;
}

template<class T>
void quicksort(std::vector<T>& v, int left, int right)
{
    if (left < right) {
        int p = partition(v, left, right);
        quicksort(v, left, p - 1);
        quicksort(v, p + 1, right);
    }
}

template<class T>
int quickselect(std::vector<T>& v, int left, int right, int k)
{
    if (left == right)
        return v[left];
    int pivpos = (left + right) / 2;
    pivpos = partition(v, left, right);
    if (k == pivpos)
        return v[k];
    else if (k < pivpos)
        right = pivpos - 1;
    else
        left = pivpos + 1;
    return quickselect(v, left, right, k);
}

int main()
{
    auto v = vector<int>({9, 3, 5, 2, 7, 6, 1, 4, 8, 0});
    cout << tostr(v) << "\n";
    quicksort(v, 0, v.size() - 1);
    cout << tostr(v) << "\n";

    int median = quickselect(v, 0, v.size() - 1, v.size() / 2);
    cout << median << "\n";
}
