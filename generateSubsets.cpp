#include <iostream>
#include <vector>
using namespace std;

// Function to print all subsets using bits
void generateSubsets(vector<int> &nums)
{
    int n = nums.size();
    int totalSubsets = 1 << n; // 2^n subsets

    for (int mask = 0; mask < totalSubsets; ++mask)
    {
        cout << "{ ";
        for (int i = 0; i < n; ++i)
        {
            // If the i-th bit is set in mask, include nums[i]
            if ((mask >> i) & 1)
            {
                cout << nums[i] << " ";
            }
        }
        cout << "}" << endl;
    }
}

int main()
{
    int n;
    cout << "Enter size of the set: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements of the set:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    cout << "\nAll subsets are:\n";
    generateSubsets(nums);

    return 0;
}
