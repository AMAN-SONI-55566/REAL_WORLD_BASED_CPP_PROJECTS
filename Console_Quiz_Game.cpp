#include <iostream>
#include <vector>
#include <cctype>  // for toupper
using namespace std;

// Struct to hold each quiz question and options
struct Question {
    string questionText;
    string optionA;
    string optionB;
    string optionC;
    string optionD;
    char correctOption;  // Expected answer: 'A', 'B', 'C', or 'D'
};

// Function to ask a question and return the user's answer
char askQuestion(const Question& q) {
    char userAnswer;

    cout << q.questionText << "\n";
    cout << q.optionA << "\n";
    cout << q.optionB << "\n";
    cout << q.optionC << "\n";
    cout << q.optionD << "\n";

    // Loop until a valid input is received
    while (true) {
        cout << "Your answer (A/B/C/D): ";
        cin >> userAnswer;
        userAnswer = toupper(userAnswer);

        if (userAnswer == 'A' || userAnswer == 'B' || userAnswer == 'C' || userAnswer == 'D') {
            return userAnswer;
        }
        cout << "Invalid input. Please enter A, B, C, or D.\n";
    }
}

int main() {
    vector<Question> quiz = {
        {"What is the capital of India?", "A) Mumbai", "B) New Delhi", "C) Kolkata", "D) Chennai", 'B'},
        {"Who was the first Prime Minister of India?", "A) Jawaharlal Nehru", "B) Mahatma Gandhi", "C) Indira Gandhi", "D) Lal Bahadur Shastri", 'A'},
        {"Which festival is known as the Festival of Lights?", "A) Holi", "B) Diwali", "C) Eid", "D) Pongal", 'B'},
        {"What is the national animal of India?", "A) Tiger", "B) Elephant", "C) Lion", "D) Peacock", 'A'},
        {"Where is the Taj Mahal located?", "A) Jaipur", "B) Agra", "C) Delhi", "D) Lucknow", 'B'}
    };

    cout << "Welcome to the India Quiz! Please select A, B, C, or D for each question.\n\n";

    int score = 0;

    for (int i = 0; i < static_cast<int>(quiz.size()); ++i) {
        cout << "Q" << (i + 1) << ": ";
        char answer = askQuestion(quiz[i]);

        if (answer == quiz[i].correctOption) {
            cout << "Correct!\n\n";
            ++score;
        } else {
            cout << "Wrong! The correct answer was " << quiz[i].correctOption << ".\n\n";
        }
    }

    cout << "Quiz completed! Your total score is: " << score << " out of " << quiz.size() << ".\n";

    return 0;
}

/*

Summary:

1. Humne ek structure banaya jo question ko define karta hai.
2. Multiple questions ek vector me store kiye.
3. Ek function banaya jo question dikhata aur valid answer leta.
4. Loop me sab questions chalaye aur score count kiya.
5. Last me final score bataya.

*/