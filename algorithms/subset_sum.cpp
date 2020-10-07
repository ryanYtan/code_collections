#include <iostream>
#include <vector>

std::vector<int> numbers;

bool has_subset_sum_memo_helper(int i, int target, std::vector<std::vector<int>>& memotable)
{
    if (target < 0) // this is the backtracking part
        return false;
    if (target == 0)
        memotable[i][target] = 1;
    if (i == 0 && target > 0)
        memotable[i][target] = 0;

    if (memotable[i][target] == -1) {
        memotable[i][target] = has_subset_sum_memo_helper(i - 1, target, memotable)
                || has_subset_sum_memo_helper(i - 1, target - numbers[i], memotable);
    }
    return memotable[i][target];
}

bool has_subset_sum_memo(int i, int target)
{
    std::vector<std::vector<int>> memotable;
    for (int j = 0; j < i + 1; j++) {
        std::vector<int> arr(target + 1, -1);
        memotable.push_back(arr);
    }
    return has_subset_sum_memo_helper(i, target, memotable);
}

bool has_subset_sum(int i, int target)
{
    if (target < 0) // this is the backtracking part
        return false;
    if (target == 0)
        return true;
    if (i == 0 && target > 0)
        return false;
    return has_subset_sum(i - 1, target)
            || has_subset_sum(i - 1, target - numbers[i]);
}

int main()
{
    numbers = std::vector<int>({3, 5, 7, 10, 12});
    std::cout << has_subset_sum(numbers.size() - 1, 14) << "\n";
    std::cout << has_subset_sum(numbers.size() - 1, 12) << "\n";
    std::cout << has_subset_sum_memo(numbers.size() - 1, 14) << "\n";
    std::cout << has_subset_sum_memo(numbers.size() - 1, 12) << "\n";
}
