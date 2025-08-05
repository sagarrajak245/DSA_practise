#include <iostream>
#include <vector>
using namespace std;

// Function to build prefix sum array
vector<int> buildPrefixSum(const vector<int> &nums)
{
    int n = nums.size();
    vector<int> prefix(n);
    prefix[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + nums[i];
    }
    return prefix;
}

// Function to get sum of nums[l..r] using prefix sums
int getRangeSum(const vector<int> &prefix, int l, int r)
{
    if (l == 0)
    {
        return prefix[r];
    }
    return prefix[r] - prefix[l - 1];
}

int main()
{
    // ✅ Predefined array
    vector<int> nums = {1, 2, 3, 4, 5};

    // ✅ Build prefix sums
    vector<int> prefix = buildPrefixSum(nums);

    // ✅ Print array
    cout << "Array: ";
    for (int val : nums)
    {
        cout << val << " ";
    }
    cout << endl;

    // ✅ Print prefix sums
    cout << "Prefix sums: ";
    for (int val : prefix)
    {
        cout << val << " ";
    }
    cout << endl;

    // ✅ Predefined queries: pairs of (l, r)
    vector<pair<int, int>> queries = {
        {1, 3},
        {0, 4},
        {2, 2}};

    // ✅ Answer queries
    cout << "\nAnswering queries:\n";
    for (auto q : queries)
    {
        int l = q.first;
        int r = q.second;

        int sum = getRangeSum(prefix, l, r);
        cout << "Sum of nums[" << l << ".." << r << "] = " << sum << endl;
    }

    return 0;
}
