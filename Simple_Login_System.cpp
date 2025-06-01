#include <iostream>
#include <string>

using namespace std;

int main() {
    const string correctUsername = "GithubUser";
    const string correctPassword = "Github@123";

    const int maxAttempts = 3;
    int attempts = 0;
    bool loggedIn = false;

    while (attempts < maxAttempts && !loggedIn) {
        string username, password;

        cout << "Enter username: ";
        getline(cin, username);

        cout << "Enter password: ";
        getline(cin, password);

        if (username == correctUsername && password == correctPassword) {
            cout << "Login successful! Welcome, " << username << ".\n";
            loggedIn = true;
        } else {
            attempts++;
            cout << "Incorrect username or password. ";
            if (attempts < maxAttempts) {
                cout << "Please try again. (" << (maxAttempts - attempts) << " attempts left)\n";
            } else {
                cout << "No attempts left. Access denied.\n";
            }
        }
    }

    return 0;
}
