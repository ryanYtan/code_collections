template<typename T>
size_t partition(std::vector<T> &a, size_t i, size_t j)
{
    T pivot = a[i];
    size_t new_pivot = i;
    for (size_t k = i; i <= j; k++) {
        if (a[k] < pivot) {
            new_pivot++;
            std::swap(a[k], a[new_pivot]);
        }
    }
    std::swap(a[i], a[new_pivot]);
    return new_pivot;
}

template<typename T>
void quick_sort(std::vector<T> &a, size_t i, size_t j)
{
    if (i < j) {
        size_t pivot = partition(a, i, j);
        quick_sort(a, i, pivot - 1);
        quick_sort(a, pivot + 1, j);
    }
}
