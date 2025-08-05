#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

// 1. Reverse a string
void reverseString(string &str)
{
    int left = 0, right = str.size() - 1;
    while (left < right)
        swap(str[left++], str[right--]);
}

// 2. Check for palindrome
bool isPalindrome(const string &str)
{
    int left = 0, right = str.size() - 1;
    while (left < right)
        if (str[left++] != str[right--])
            return false;
    return true;
}

// 3. Count vowels and consonants
void countVowelsConsonants(const string &str)
{
    int vowels = 0, consonants = 0;
    for (char c : str)
    {
        if (isalpha(c))
        {
            c = tolower(c);
            if (string("aeiou").find(c) != string::npos)
                vowels++;
            else
                consonants++;
        }
    }
    cout << "Vowels: " << vowels << ", Consonants: " << consonants << "\n";
}

// 4. Frequency of characters
void characterFrequency(const string &str)
{
    unordered_map<char, int> freq;
    for (char c : str)
        freq[c]++;
    for (auto &pair : freq)
        cout << pair.first << ": " << pair.second << "\n";
}

// 5. Remove duplicate characters
string removeDuplicates(const string &str)
{
    unordered_set<char> seen;
    string result = "";
    for (char c : str)
    {
        if (!seen.count(c))
        {
            seen.insert(c);
            result += c;
        }
    }
    return result;
}

// 6. Check if two strings are anagrams
bool isAnagram(const string &s1, const string &s2)
{
    if (s1.length() != s2.length())
        return false;
    vector<int> count(26, 0);
    for (char c : s1)
        count[c - 'a']++;
    for (char c : s2)
        count[c - 'a']--;
    return all_of(count.begin(), count.end(), [](int i)
                  { return i == 0; });
}

// 7. Convert to lowercase and uppercase
void convertCases(const string &str)
{
    string lower = "", upper = "";
    for (char c : str)
    {
        lower += tolower(c);
        upper += toupper(c);
    }
    cout << "Lowercase: " << lower << "\nUppercase: " << upper << "\n";
}

// 8. Longest word in a sentence
string longestWord(const string &str)
{
    stringstream ss(str);
    string word, longest = "";
    while (ss >> word)
        if (word.length() > longest.length())
            longest = word;
    return longest;
}

// 9. First non-repeating character
char firstNonRepeating(const string &str)
{
    unordered_map<char, int> freq;
    for (char c : str)
        freq[c]++;
    for (char c : str)
        if (freq[c] == 1)
            return c;
    return '\0'; // or return -1;
}

// 10. Check if two strings are rotations
bool areRotations(const string &s1, const string &s2)
{
    return s1.length() == s2.length() && (s1 + s1).find(s2) != string::npos;
}

// MAIN
int main()
{
    string input1, input2;
    int choice;

    do
    {
        cout << "\nChoose a problem to run (1-10):\n";
        cout << "1. Reverse a string\n";
        cout << "2. Check palindrome\n";
        cout << "3. Count vowels & consonants\n";
        cout << "4. Character frequency\n";
        cout << "5. Remove duplicates\n";
        cout << "6. Anagram check\n";
        cout << "7. Convert to lower/upper\n";
        cout << "8. Longest word in sentence\n";
        cout << "9. First non-repeating character\n";
        cout << "10. Check rotations\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear newline after number input

        switch (choice)
        {
        case 1:
            cout << "Enter a string: ";
            getline(cin, input1);
            reverseString(input1);
            cout << "Reversed: " << input1 << "\n";
            break;
        case 2:
            cout << "Enter a string: ";
            getline(cin, input1);
            cout << (isPalindrome(input1) ? "Palindrome" : "Not Palindrome") << "\n";
            break;
        case 3:
            cout << "Enter a string: ";
            getline(cin, input1);
            countVowelsConsonants(input1);
            break;
        case 4:
            cout << "Enter a string: ";
            getline(cin, input1);
            characterFrequency(input1);
            break;
        case 5:
            cout << "Enter a string: ";
            getline(cin, input1);
            cout << "Without duplicates: " << removeDuplicates(input1) << "\n";
            break;
        case 6:
            cout << "Enter string 1: ";
            getline(cin, input1);
            cout << "Enter string 2: ";
            getline(cin, input2);
            cout << (isAnagram(input1, input2) ? "Anagrams" : "Not Anagrams") << "\n";
            break;
        case 7:
            cout << "Enter a string: ";
            getline(cin, input1);
            convertCases(input1);
            break;
        case 8:
            cout << "Enter a sentence: ";
            getline(cin, input1);
            cout << "Longest word: " << longestWord(input1) << "\n";
            break;
        case 9:
            cout << "Enter a string: ";
            getline(cin, input1);
            {
                char res = firstNonRepeating(input1);
                if (res)
                    cout << "First non-repeating: " << res << "\n";
                else
                    cout << "No non-repeating character.\n";
            }
            break;
        case 10:
            cout << "Enter string 1: ";
            getline(cin, input1);
            cout << "Enter string 2: ";
            getline(cin, input2);
            cout << (areRotations(input1, input2) ? "Rotations" : "Not Rotations") << "\n";
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
