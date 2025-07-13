
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <list>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {

        unordered_set<string> wordset(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;

        // edge case
        if (wordset.find(endWord) == wordset.end())
        {
            return 0;
        }
        q.push({beginWord, 1});

        while (!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            // check ans
            if (word == endWord)
                return steps;

            // now loop sagar and replace each char and find in set , if yes then push in queu with step++
            //  and erase from set and restor it befor moving to next char in word okey

            for (int i = 0; i < word.size(); i++)
            {
                char originalchar = word[i];

                for (char c = 'a'; c <= 'z'; ++c)
                {

                    if (c == originalchar)
                        continue;
                    word[i] = c;

                    // check if any word list foundif yes then add in queu and erase from set

                    if (wordset.find(word) != wordset.end())
                    {
                        q.push({word, steps + 1});
                        wordset.erase(word);
                    }
                }

                word[i] = originalchar;
            }
        }

        return 0;
    }
};

int main()
{
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    int result = sol.ladderLength(beginWord, endWord, wordList);
    cout << "Length of the shortest transformation sequence: " << result << endl;
    return 0;
}
