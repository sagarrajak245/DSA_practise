
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <sstream>
using namespace std;

int main()
{

    // Count occurrences of a specific word
    string sentence = "I love coding in C++";
    string wordToFind = "love";
    stringstream ss(sentence);
    string word;
    int count = 0;
    while (ss >> word)
    {
        if (word == wordToFind)
        {
            count++;
        }
    }
    if (count > 0)
    {
        cout << "'" << wordToFind << "' found " << count << " times\n";
    }
    else
    {
        cout << "'" << wordToFind << "' not found\n";
    }

    return 0;
}