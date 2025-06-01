//this code generates a receipt for items purchased, including GST calculation.
// It checks if the password meets certain criteria: at least 8 characters, contains a digit, and contains an uppercase letter.
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isValidPassword(const string &pwd, string &err)
{
    if (pwd.length() < 8)
    {
        err = "At least 8 characters required.";
        return false;
    }
    bool hasDigit = false, hasUpper = false;
    for (char c : pwd)
    {
        if (isdigit((unsigned char)c))
            hasDigit = true;
        if (isupper((unsigned char)c))
            hasUpper = true;
    }
    if (!hasDigit)
    {
        err = "Must contain a digit.";
        return false;
    }
    if (!hasUpper)
    {
        err = "Must contain an uppercase letter.";
        return false;
    }
    return true;
}

int main()
{
    cout << "Enter password: ";
    string password, error;
    getline(cin, password);

    if (isValidPassword(password, error))
        cout << "Password is valid.\n";
    else
        cout << "Invalid password: " << error << "\n";

    return 0;
}
