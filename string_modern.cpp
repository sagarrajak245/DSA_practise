#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <regex>

using namespace std;

int main()
{
    // cout << "================== 1. Basic C-style string ==================\n";
    // char name[50];
    // cout << "Enter your name (C-style): ";
    // cin.getline(name, 50);
    // cout << "Hello, " << name << endl;

    // cout << "\n================== 2. std::string basic input/output ==================\n";
    // string myName;
    // cout << "Enter your name (std::string, single word): ";
    // cin >> myName;
    // cout << "Hello, " << myName << endl;
    // cin.ignore(); // clear newline left in buffer

    // cout << "\nEnter a full sentence: ";
    // string sentence;
    // getline(cin, sentence);
    // cout << "You entered: " << sentence << endl;

    cout << "\n================== 3. Concatenation ==================\n";
    string a = "Hello, ";
    string b = "World!";
    string c = a + b;
    cout << "Concatenated: " << c << endl;

    cout << "\n================== 4. String Length ==================\n";
    cout << "Length of \"" << c << "\": " << c.length() << endl;

    cout << "\n================== 5. Access and Modify Characters ==================\n";
    cout << "Original: " << c << endl;
    c[7] = 'w';
    cout << "Modified: " << c << endl;

    cout << "\n================== 6. Iterate over String ==================\n";
    cout << "Using index: ";
    for (int i = 0; i < c.size(); i++)
    {
        cout << c[i] << " ";
    }
    cout << "\nUsing range-based for: ";
    for (char ch : c)
    {
        cout << ch << " ";
    }
    cout << endl;

    cout << "\n================== 7. Substrings ==================\n";
    string sub = c.substr(0, 5);
    cout << "Substring (0,5): " << sub << endl;

    cout << "\n================== 8. Find in String ==================\n";
    string text = "I love programming in C++";
    size_t pos = text.find("love");
    if (pos != string::npos)
    {
        cout << "'love' found at position: " << pos << endl;
    }
    else
    {
        cout << "'love' not found\n";
    }

    cout << "\n================== 9. Replace in String ==================\n";
    string s = "I like cats";
    s.replace(7, 4, "dogs");
    cout << "Replaced: " << s << endl;

    cout << "\n================== 10. Erase in String ==================\n";
    string eraseExample = "Hello World";
    eraseExample.erase(5, 2);
    cout << "After erase: " << eraseExample << endl;

    cout << "\n================== 11. Insert in String ==================\n";
    eraseExample.insert(5, " ");
    cout << "After insert: " << eraseExample << endl;

    cout << "\n================== 12. Compare Strings ==================\n";
    string str1 = "apple";
    string str2 = "apple";
    if (str1 == str2)
    {
        cout << "Strings are equal\n";
    }
    else
    {
        cout << "Strings are not equal\n";
    }

    cout << "\n================== 13. String to Number and Back ==================\n";
    string numStr = "123";
    int num = stoi(numStr);
    cout << "String to int + 5 = " << (num + 5) << endl;

    int anotherNum = 456;
    string anotherStr = to_string(anotherNum);
    cout << "Int to string: " << anotherStr << endl;

    cout << "\n================== 14. Splitting String with StringStream ==================\n";
    string fruits = "apple orange banana";
    stringstream ss(fruits);
    string word;
    cout << "Words:\n";
    while (ss >> word)
    {
        cout << word << endl;
    }

    cout << "\n================== 15. Splitting with Delimiter ==================\n";
    string csv = "red,green,blue,yellow";
    stringstream ss2(csv);
    string token;
    while (getline(ss2, token, ','))
    {
        cout << token << endl;
    }

    cout << "\n================== 16. Reverse a String ==================\n";
    string rev = "hello";
    reverse(rev.begin(), rev.end());
    cout << "Reversed: " << rev << endl;

    cout << "\n================== 17. Sorting Characters ==================\n";
    string toSort = "dcba";
    sort(toSort.begin(), toSort.end());
    cout << "Sorted: " << toSort << endl;

    cout << "\n================== 18. Regex Matching ==================\n";
    cout << "Enter text to search for an email address: ";
    string input;
    getline(cin, input);
    regex emailPattern(R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}\b)");
    if (regex_search(input, emailPattern))
    {
        cout << "Email found!" << endl;
    }
    else
    {
        cout << "No email found." << endl;
    }

    cout << "\n================== 19. Regex Extract All Numbers ==================\n";
    string numText = "Order 1234, price $56, quantity 78";
    regex numberRegex("\\d+");
    auto begin = sregex_iterator(numText.begin(), numText.end(), numberRegex);
    auto end = sregex_iterator();

    cout << "Numbers found:\n";
    for (auto i = begin; i != end; ++i)
    {
        cout << i->str() << endl;
    }

    cout << "\n================== The End of Demo ==================\n";
    return 0;
}
