template<typename T>
void insertion_sort(std::vector<T> &a)
{
    for (size_t i = 1; i < a.size(); i++) {
        T curr = a[i];
        size_t j = i - 1;
        while (j >= 0 && a[j] > curr) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = curr;
    }
}
