#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//  Base Case: Two Sum with two pointers
vector<vector<int>> twoSum(vector<int> &nums, int start, int target)
{
    vector<vector<int>> res;
    int left = start, right = nums.size() - 1;

    while (left < right)
    {
        int sum = nums[left] + nums[right];

        if (sum == target)
        {
            res.push_back({nums[left], nums[right]});
            left++;
            right--;

            // Skip duplicates
            while (left < right && nums[left] == nums[left - 1])
                left++;
            while (left < right && nums[right] == nums[right + 1])
                right--;
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return res;
}

// ✅Recursive kSum function
vector<vector<int>> kSum(vector<int> &nums, int start, int k, int target)
{
    vector<vector<int>> res;
    int n = nums.size();

    if (k == 2)
    {
        return twoSum(nums, start, target);
    }

    for (int i = start; i < n - k + 1; i++)
    {
        if (i > start && nums[i] == nums[i - 1])
            continue;

        // Optional optimization
        long long min_possible = (long long)nums[i] + (long long)nums[i + 1] * (k - 1);
        long long max_possible = (long long)nums[i] + (long long)nums[n - 1] * (k - 1);
        if (min_possible > target)
            break;
        if (max_possible < target)
            continue;

        vector<vector<int>> temp = kSum(nums, i + 1, k - 1, target - nums[i]);

        for (auto &t : temp)
        {
            t.insert(t.begin(), nums[i]);
            res.push_back(t);
        }
    }

    return res;
}

// ✅ Wrapper functions
vector<vector<int>> twoSumWrapper(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    return kSum(nums, 0, 2, target);
}

vector<vector<int>> threeSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    return kSum(nums, 0, 3, target);
}

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    return kSum(nums, 0, 4, target);
}

vector<vector<int>> fiveSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    return kSum(nums, 0, 5, target);
}

// ✅ Main function
int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    cout << "2Sum:\n";
    auto res2 = twoSumWrapper(nums, target);
    for (auto &pair : res2)
    {
        for (int x : pair)
            cout << x << " ";
        cout << endl;
    }

    cout << "\n3Sum:\n";
    auto res3 = threeSum(nums, target);
    for (auto &triplet : res3)
    {
        for (int x : triplet)
            cout << x << " ";
        cout << endl;
    }

    cout << "\n4Sum:\n";
    auto res4 = fourSum(nums, target);
    for (auto &quad : res4)
    {
        for (int x : quad)
            cout << x << " ";
        cout << endl;
    }

    cout << "\n5Sum:\n";
    vector<int> nums5 = {1, 0, -1, 0, -2, 2, -3};
    int target5 = 0;
    auto res5 = fiveSum(nums5, target5);
    for (auto &quint : res5)
    {
        for (int x : quint)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}
