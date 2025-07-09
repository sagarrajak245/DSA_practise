#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <sstream>
using namespace std;

int main()
{

    // Split a sentence into words
    //   Task : Print each word on a new line.
    string sentence = "I love coding in C++";

    stringstream ss(sentence);
    string word;

    while (ss >> word)
    {
        cout << word << endl;
    }

    // Split a comma-separated string
    //   Task : Print each item on a new line.

    return 0;
}