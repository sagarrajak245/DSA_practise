#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <sstream>
using namespace std;

int main()
{

    // Save all words into a vector<string> and then print them..
    string sentence = "I love coding in C++";

    stringstream ss(sentence);
    string word;
    vector<string> words;
    int cnt = 0;
    while (ss >> word)
    {
        cout << word << endl;
        cnt++;
        words.push_back(word);
    }
    cout << "Total words: " << cnt << endl;

    for (auto it : words)
    {
        cout << it << " ";
    }

    return 0;
}