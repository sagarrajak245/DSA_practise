

#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <sstream>
using namespace std;

int main()
{

    // Split with custom delimiter (,)
    string sentence = "apple,orange,banana";
    // stringstream ss(sentence);
    // string item;
    // cout << "Items:\n";
    // while (getline(ss, item, ','))
    // {
    //     cout << item << endl;
    // }
    // cout << "\nTotal items: " << count(sentence.begin(), sentence.end(), ',') + 1 << endl;
    // // Note: count() counts the number of commas, so we add 1 to get the total number of items.

    // other way to split with custom delimiter

    while (sentence.length() > 0)
    {
        int pos = sentence.find(',');
        if (pos == string::npos)
        {
            cout << sentence << endl; // Print the last item
            sentence = "";            // Clear the string
        }
        else
        {
            cout << sentence.substr(0, pos) << endl; // Print the item before the comma
            sentence = sentence.substr(pos + 1);     // Remove the printed item and the comma
        }
    }

    return 0;
}