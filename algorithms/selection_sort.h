template<typename T>
void selection_sort(std::vector<T> &a)
{
    T min = a[0];
    bool swapped;
    size_t i = 0;
    do {
        swapped = false;
        size_t min_pos = i;
        for (size_t j = i + 1; j < a.size(); j++) {
            if (a[j] < a[min_pos]) {
                min_pos = j;
                swapped = true;
            }
        }
        std::swap(a[min_pos], a[i]);
        i++;
    } while (swapped);
}
