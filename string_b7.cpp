

#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <sstream>
using namespace std;

int main()
{

    // Remove all spaces from a sentence
    string sentence = "apple,orange,banana are my favorite fruits";
    stringstream ss(sentence);
    string word;
    string result;
    while (ss >> word)
    {
        result += word; // Concatenate words without spaces
    }
    cout << "Without spaces: " << result << endl;
    // Alternatively, using std::remove_if and erase
    sentence.erase(remove_if(sentence.begin(), sentence.end(), ::isspace), sentence.end());
    cout << "Without spaces (using erase): " << sentence << endl;
    // Note: The first method concatenates words, while the second method removes all spaces from the original string.

    return 0;
}