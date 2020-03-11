template<typename T>
bool _bubble_pass(std::vector<T> &a, std::size_t len)
{
    bool swapped = false;
    for (std::size_t i = 0; i < len - 1; i++) {
        if (a[i] > a[i + 1]) {
            std::swap(a[i], a[i + 1]);
            swapped = true;
        }
    }
    return swapped;
}

template<typename T>
void bubble_sort(std::vector<T> &a)
{
    size_t len = a.size();
    while (_bubble_pass(a, len))
        len--;
}
