#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        unordered_map<string, int> freq;
        // key point if pair then  4char contribute
        // and same char present then 2 char contribute

        int total_length = 0;

        bool has_center = false;

        // step1
        for (auto it : words)
        {
            freq[it]++;
        }

        // step2

        for (auto it : freq)
        {

            string word = it.first;
            int count = it.second;
            string rev = word;
            reverse(rev.begin(), rev.end());
            if (word == rev)
            {
                int pairs = count / 2;
                total_length += pairs * 4;
                freq[word] -= pairs * 2; // each pair contributes 4 characters
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<string> words1 = {"lc", "cl", "gg"};
    cout << sol.longestPalindrome(words1) << endl; // Output: 6

    vector<string> words2 = {"ab", "ty", "yt", "lc", "cl", "ab"};
    cout << sol.longestPalindrome(words2) << endl; // Output: 8

    return 0;
}