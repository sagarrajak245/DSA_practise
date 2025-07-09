#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string sentence = "apple,orange,banana are my favorite fruits";

    // Replace commas with spaces
    for (char &ch : sentence)
    {
        if (ch == ',')
            ch = ' ';
    }

    stringstream ss(sentence);
    string word;
    vector<string> words;

    while (ss >> word)
    {
        words.push_back(word);
    }

    sort(words.begin(), words.end());

    string result = "";
    for (int i = 0; i < words.size(); i++)
    {
        if (i > 0)
            result += ", ";

        result += words[i];
    }

    cout << "Sorted words: " << result << endl;

    return 0;
}
// This code takes a sentence, replaces commas with spaces, splits it into words, sorts the words alphabetically, and then prints them as a comma-separated string.