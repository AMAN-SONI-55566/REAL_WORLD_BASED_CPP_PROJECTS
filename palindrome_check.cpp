/*
    Problem: Palindrome Checker
    ----------------------------
    Ask the user for a word and check if it's a palindrome.
    A palindrome is a word that reads the same forwards and backwards.

    Example:
    Input : madam
    Output: Palindrome

    Skills: Strings, loops
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string word;
    cout << "Enter a word: ";
    cin >> word;

    int n = word.length();
    bool isPalindrome = true;

    // Check each character from both ends
    for (int i = 0; i < n / 2; ++i) {
        if (word[i] != word[n - i - 1]) {
            isPalindrome = false;
            break;
        }
    }

    // Output result
    if (isPalindrome) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not a palindrome" << endl;
    }

    return 0;
}

// we can use the same program to check for palindromes in numbers as well
// for example, if the user inputs 12321, the program will output "Palindrome"
//we just has to change the input prompt to "Enter a number: " and it will work the same way
// Note: This program is case-sensitive. To make it case-insensitive, you can convert the string to lowercase before checking.