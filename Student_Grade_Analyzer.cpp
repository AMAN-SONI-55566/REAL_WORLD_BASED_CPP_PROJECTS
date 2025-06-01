#include <iostream>
using namespace std;

int main() {
    const int numSubjects = 5;
    int marks[numSubjects];
    int total = 0;
    float average;
    bool pass = true;

    // Input marks
    cout << "Enter marks for 5 subjects (out of 100):\n";
    for (int i = 0; i < numSubjects; i++) {
        cout << "Subject " << (i + 1) << ": ";
        cin >> marks[i];

        if (marks[i] < 0 || marks[i] > 100) // || is a logical OR operator , checks condition for invalid marks
        {
            cout << "Invalid marks! Please enter values between 0 and 100.\n";
            return 1; // Exit if invalid marks entered
        }

        total += marks[i];
        if (marks[i] < 35) {
            pass = false; // If any subject is below 35, it's a fail
            cout<<"Subject " << (i + 1) << " is below passing marks. You are considered failed in this subject.\n";
        }
    }

    // Calculate average
    average = static_cast<float>(total) / numSubjects;

    // Display results
    cout << "\nAverage Marks: " << average << endl;

    if (pass) {
        cout << "Status: Pass\n";

        // Assign grade
        if (average >= 75) {
            cout << "Grade: A\n";
        } else if (average >= 60) {
            cout << "Grade: B\n";
        } else {
            cout << "Grade: C\n";
        }

    } else {
        cout << "Status: Fail\n";
        cout << "Grade: Fail\n";
    }

    return 0;
}
