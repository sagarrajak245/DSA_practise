#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string &s)
{
    if (s.empty())
        return 0;

    int n = s.length();
    int maxLength = 0;
    unordered_set<char> seen; // Changed to char type

    int left = 0, right = 0;
    while (right < n)
    {
        if (seen.find(s[right]) != seen.end())
        {
            seen.erase(s[left]);
            left++;
        }
        else
        {
            seen.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
            right++;
        }
    }

    return maxLength;
}

int main()
{
    string input;
    cout << "Enter a string: ";
    getline(cin, input); // Using getline to handle spaces

    cout << "Longest substring without repeating characters: "
         << lengthOfLongestSubstring(input) << endl;

    return 0;
}