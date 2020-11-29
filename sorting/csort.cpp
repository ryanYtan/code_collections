#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> get_c(const vector<int>& nums)
{
    int max = *max_element(nums.begin(), nums.end());
    vector<int> c(max + 1);

    for (int n : nums)
        c[n] += 1;

    // cumulative add
    for (int i = 1; i < c.size(); i++)
        c[i] = c[i] + c[i - 1];

    // shift vector elements to right by one
    for (int i = c.size() - 1; i >= 0; i--) {
        if (i == 0)
            c[i] = 0;
        else
            c[i] = c[i - 1];
    }

    return c;
}

template<class T>
void print_vect(const vector<T>& el)
{
    if (el.empty()) {
        return;
    }

    auto it = el.begin();
    std::cout << "[" << *it;
    for ((void)++it; it != el.end(); (void)++it) {
        std::cout << ", " << *it;
    }
    std::cout << "]\n";
}

vector<int> csort(const vector<int>& nums)
{
    vector<int> c = get_c(nums);
    vector<int> sorted(nums.size());

    for (int i = 0; i < nums.size(); i++) {
        auto value = nums[i];
        auto index = c[value];
        sorted[index] = value;
        c[value]++;
    }

    return sorted;
}

int main()
{
    vector<int> nums({3, 2, 6, 3, 7, 3, 0, 5});
    vector<int> sorted = csort(nums);
    print_vect(sorted);
}
