#include <iostream>
#include <string>
#include <cctype>   // for isalpha and toupper

using namespace std;

// Function to format initials from a full name
// const reference to avoid copying
string formatInitials(const string& fullName) {
    string initials;
    bool isNewWord = true;  // Flag to identify start of a word

    for (char ch : fullName) {
        // Check if character is a letter
        if (!isalpha(ch) && ch != ' ') {
            continue;  // Skip non-letter characters except spaces like @ , ! etc
        }
        if (isNewWord && isalpha(ch)) {
            initials += toupper(ch);  // Append uppercase initial
            initials += '.';          // Append dot after initial
            isNewWord = false;        // Reset flag until next space
        }

        if (ch == ' ') {
            isNewWord = true;         // Next character starts a new word
        }
    }

    return initials;
}

int main() {
    cout << "Enter full name: ";
    string fullName;
    getline(cin, fullName);  // Read full line including spaces

    string initials = formatInitials(fullName); // Call function to format initials

    cout << "Formatted initials: " << initials << endl; // Display formatted initials

    return 0;
}
