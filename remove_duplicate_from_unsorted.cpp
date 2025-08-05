#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> removeDuplicates(vector<int> &nums)
{
    unordered_set<int> seen;
    vector<int> result;

    for (int num : nums)
    {
        if (seen.find(num) == seen.end())
        {
            seen.insert(num);
            result.push_back(num);
        }
    }
    return result;
}

int main()
{
    vector<int> arr = {4, 5, 9, 5, 4, 2, 9};
    vector<int> uniqueArr = removeDuplicates(arr);
    for (int num : uniqueArr)
    {
        cout << num << " ";
    }
}
