

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {
        unordered_set<string> wordset(bank.begin(), bank.end());
        if (wordset.find(endGene) == wordset.end())
            return -1;

        queue<pair<string, int>> q;
        q.push({startGene, 0});

        vector<char> genes = {'A', 'C', 'G', 'T'};

        while (!q.empty())
        {
            auto [gene, steps] = q.front();
            q.pop();

            if (gene == endGene)
                return steps;

            for (int i = 0; i < gene.size(); ++i)
            {
                char original = gene[i];
                for (char c : genes)
                {
                    if (c == original)
                        continue;
                    gene[i] = c;
                    if (wordset.find(gene) != wordset.end())
                    {
                        q.push({gene, steps + 1});
                        wordset.erase(gene);
                    }
                }
                gene[i] = original;
            }
        }

        return -1;
    }
};

int main()
{
    Solution sol;
    string startGene = "AAAAACCC";
    string endGene = "AACCCCCC";
    vector<string> bank = {"AAAACCCC", "AAACCCCC", "AACCCCCC", "AACCCCAA", "AACCCCAA"};

    int result = sol.minMutation(startGene, endGene, bank);
    cout << "Minimum number of mutations: " << result << endl;

    return 0;
}