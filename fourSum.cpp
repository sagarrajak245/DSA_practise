

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<vector<int>> fourSum(vector<int> nums, int target)
{

    // sort array

    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {

        if (i > 0 && nums[i] == nums[i - 1])
            continue; // same element skip kara
        // element hold karke next loop me entry

        for (int j = i + 1; j < n; j++)
        {

            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            int left = j + 1;
            int right = n - 1;

            while (left < right)
            {

                int sum = nums[left] + nums[right] + nums[i] + nums[j];

                if (sum == target)
                {

                    ans.push_back({nums[i], nums[j], nums[left], nums[right]});

                    left++;
                    right--;

                    // skip overlap

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
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};

    int target = 0;
    vector<vector<int>> output = fourSum(nums, target);
    for (auto quadraplets : output)
    {
        for (auto num : quadraplets)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}

// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]