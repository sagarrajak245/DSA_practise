#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <sstream>
using namespace std;

int main()
{

    // Split a sentence into words
    //   Task : count word.
    string sentence = "I love coding in C++";

    stringstream ss(sentence);
    string word;
    int cnt = 0;
    while (ss >> word)
    {
        cout << word << endl;
        cnt++;
    }
    cout << "Total words: " << cnt << endl;

    return 0;
}