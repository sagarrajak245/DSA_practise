#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maxGroups(vector<int> &cfactors, int n)
{
    // Your code here

    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[cfactors[i]]++;
    }
    int ans = 0;
    for (auto &it : freq)
    {
        ans += it.second / 2; // each group needs at least 2 students with the same compatibility factor
    }
    return ans;
    // if a compatibility factor has 5 students, it can form 2 groups (5
}

int main()
{

    int n;
    cin >> n;
    vector<int> cfactors(n);
    // input compatibility factors

    for (int i = 0; i < n; i++)
    {
        cin >> cfactors[i];
    }

    int ans = maxGroups(cfactors, n);

    cout << ans << endl;

    return 0;
}