#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> duplicate(vector<int> &nums)
{
    unordered_map<int, int> countMap;
    vector<int> duplicates;

    for (int num : nums)
    {
        countMap[num]++;
    }

    for (auto &it : countMap)
    {
        if (it.second > 1)
        {
            duplicates.push_back(it.first);
        }
    }

    return duplicates;
}

string rev(string &s)
{

    int start = 0;
    int end = s.length() - 1;
    while (start < end)
    {

        swap(s[start], s[end]);
        start++;
        end--;
    }
    return s;
}

int main()
{

    vector<int> nums = {1, 2, 2, 3, 4, 4, 5};

    vector<int>
        ans = duplicate(nums);
    for (auto it : ans)
    {
        cout << "duplicate arrays items are: " << it << "\n";
    }

    string s = "Hello World";
    string s1 = rev(s);
    cout << "Reversed string: " << s1 << endl;
    return 0;
}