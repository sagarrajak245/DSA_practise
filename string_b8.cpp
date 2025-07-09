#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string sentence = "apple,orange,banana are my favorite fruits";
    stringstream ss(sentence);
    string word;
    string result = "";

    while (ss >> word)
    {
        string processedWord = "";
        stringstream subss(word);
        string subword;

        // Handle comma-separated parts
        while (getline(subss, subword, ','))
        {
            if (!subword.empty())
            {
                subword[0] = toupper(subword[0]);
            }
            if (!processedWord.empty())
            {
                processedWord += ",";
            }
            processedWord += subword;
        }

        result += processedWord + " ";
    }

    cout << "Capitalized sentence: " << result << endl;

    return 0;
}
