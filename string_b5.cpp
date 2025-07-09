

#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <sstream>
using namespace std;

int main()
{

    // Find longest word
    string sentence = "I love coding in C++";
    int maxlen = INT_MIN;
    stringstream ss(sentence);
    string word;
    string longestWord;
    while (ss >> word)
    {
        int temp = word.length();
        if (temp > maxlen)
        {
            maxlen = max(maxlen, temp);
            longestWord = word;
        }
    }

    cout << "Longest word: " << longestWord << " with length " << maxlen << endl;

    return 0;
}