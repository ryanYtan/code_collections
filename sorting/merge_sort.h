template<typename T>
void _merge(std::vector<T> &a, size_t i, size_t mid, size_t j)
{
    std::vector<T> tmp;
    size_t left = i;
    size_t right = mid + 1;

    while (left <= mid && right <= j) {
        if (a[left] <= a[right]) {
            tmp.push_back(a[left++]);
        } else {
            tmp.push_back(a[right++]);
        }
    }

    while (left <= mid)
        tmp.push_back(a[left++]);
    while (right <= j)
        tmp.push_back(a[right++]);

    for (size_t k = 0; k < tmp.size(); k++) {
        a[i + k] = tmp[k];
    }
}

template<typename T>
void _merge_sort(std::vector<T> &a, size_t left, size_t right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        _merge_sort(a, left, mid);
        _merge_sort(a, mid + 1, right);
        _merge(a, left, mid, right);
    }
}

template<typename T>
void merge_sort(std::vector<T> &a) {
    _merge_sort(a, 0, a.size() - 1);
}
