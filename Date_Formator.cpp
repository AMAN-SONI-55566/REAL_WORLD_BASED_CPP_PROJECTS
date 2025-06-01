#include <iostream>
#include <string>
using namespace std;

int main() {
    string date;
    cout << "Enter date in DDMMYYYY format: ";
    cin >> date;

    // Array of month names
    string months[12] = { "January", "February", "March", "April", "May", "June",
                          "July", "August", "September", "October", "November", "December" };

    // Extract parts from the input string
    string day = date.substr(0, 2);
    string monthStr = date.substr(2, 2);
    string year = date.substr(4, 4);

    // Convert month string to integer
    int month = stoi(monthStr);

    // Validate month range
    if (month >= 1 && month <= 12) {
        cout << day << " " << months[month - 1] << " " << year << endl;
    } else {
        cout << "Invalid month!" << endl;
    }

    return 0;
}
