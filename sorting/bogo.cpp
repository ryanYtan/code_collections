#include <iostream>
#include <vector>
#include <ctime>
#include <unordered_set>
using namespace std;

void print(vector<int>& nums)
{
    if (nums.empty())
        return;

    printf("[%2d", nums[0]);
    for (int i = 1; i < nums.size(); i++) {
        printf(", %2d", nums[i]);
    }
    printf("]\n");
}

// Modern Fisher-Yates shuffle
void shuffle(vector<int>& nums)
{
    for (int i = nums.size() - 1; i >= 1; i--) {
        int j = rand() % (i + 1);
        swap(nums[i], nums[j]);
    }
}

bool is_sorted(const vector<int>& nums)
{
    for (int i = 0; i < nums.size() - 1; i++)
        if (nums[i] > nums[i + 1])
            return false;
    return true;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: bogo N\n");
        return 1;
    }
    srand(time(NULL));

    int n = atoi(argv[1]);
    vector<int> nums(n);

    for (int i = 1; i <= n; i++)
        nums[i - 1] = i;

    shuffle(nums);

    int i = 1;
    while (!is_sorted(nums)) {
        i++;
//        print(nums);
        shuffle(nums);
    }
//    print(nums);
//    printf("\nFinished in %d tries.\n", i - 1);
    printf("%d\n", i - 1);
    return 0;
}
