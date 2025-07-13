// Optimized Approach - O(n^2 logn + nlogn) - o(n^2 logn) time and O(n) space

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
    // vector<vector<int>> threeSum(vector<int> &nums)
    // {
    //     int target = 0;
    //     sort(nums.begin(), nums.end());
    //     set<vector<int>> s;
    //     vector<vector<int>> output;
    //     for (int i = 0; i < nums.size(); i++)
    //     {
    //         int j = i + 1;
    //         int k = nums.size() - 1;
    //         while (j < k)
    //         {
    //             int sum = nums[i] + nums[j] + nums[k];
    //             if (sum == target)
    //             {
    //                 s.insert({nums[i], nums[j], nums[k]});
    //                 j++;
    //                 k--;
    //             }
    //             else if (sum < target)
    //             {
    //                 j++;
    //             }
    //             else
    //             {
    //                 k--;
    //             }
    //         }
    //     }
    //     for (auto triplets : s)
    //         output.push_back(triplets);
    //     return output;
    // }

    vector<vector<int>> threeSum(vector<int> &nums)
    {

        // Sort the input array
        // convert three loop to two loop like reduce threesum to twosum
        // assign left ,right
        // and target=-nums[i] now classic two sum problem solve it
        // avoid same character

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {

            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            } // continue

            int left = i + 1;
            int right = n - 1;
            int target = -nums[i];

            // now loop like two sum

            while (left < right)
            {
                int sum = nums[left] + nums[right];

                if (target == sum)
                { // a+b+c=0  is same a+b=-c
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    // skip duplicate

                    while (left < right && nums[left] == nums[left - 1])
                        ;
                    while (left < right && nums[right] == nums[right + 1])
                        ;
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
        }

        return ans;
    }
};

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution s;
    vector<vector<int>> output = s.threeSum(nums);
    for (auto triplets : output)
    {
        for (auto num : triplets)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}