#include <deque>

constexpr auto BASE = 10;

size_t get_wordsize(int n)
{
    size_t counter = 0;
    while (n > 0) {
        n /= 10;
        counter++;
    }
    return counter;
}

int max_element(std::vector<int> &a)
{
    int max = a[0];
    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

void radix_lsd_sort(std::vector<int> &a)
{
    int max = max_element(a);
    size_t max_wordsize = get_wordsize(max);
    size_t exponent = 1;

    while (max_wordsize > 0) {

        std::vector<std::deque<int>> buckets(BASE, std::deque<int>());

        for (size_t i = 0; i < a.size(); i++) {
            int num = a[i];
            int bucket_num = (num / exponent) % BASE;
            buckets[bucket_num].push_back(num);
        }

        size_t i = 0;
        for (auto q : buckets) {
            while (!q.empty()) {
                int num = q.front();
                a[i++] = num;
                q.pop_front();
            }
        }

        exponent *= BASE;
        max_wordsize--;
    }
}
