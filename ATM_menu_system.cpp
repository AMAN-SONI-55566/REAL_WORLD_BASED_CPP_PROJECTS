// Explanation:
//  Class ATM encapsulates balance and operations.
//  PIN authentication is done once at program start.
//  Balance is saved to and loaded from balance.txt for persistence.
//  Functions like deposit, withdraw, and checkBalance manage the logic.
//  Main menu loops till exit.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ATM
{
private:
    double balance;                            // stores the balance
    const string balanaceflie = "balance.txt"; // file to store balance
    const string pin = "233330";               // hardcoded PIN for simplicity

    // Load balance from file
    void loadBalance()
    {
        ifstream infile(balanaceflie); // load balance from file
        if (infile.is_open())
        {
            infile >> balance;
            infile.close();
        }
        else
        {
            balance = 0.0f; // File not found, initialize balance
        }
    }
    // function to save balance to file
    void saveBalance()
    {
        ofstream outfile(balanaceflie); // save balance to file
        if (outfile.is_open())
        {                       // check if file is open
            outfile << balance; // write balance to file
            outfile.close();
        }
    }

public:
    ATM() : balance(0.0)
    {
        loadBalance(); // Load balance from file on initialization
    }

    bool authenticate()
    {
        string entered_Pin;
        cout << "enter your 6 digit pin: ";
        cin >> entered_Pin;          // take pin input from user
        return (entered_Pin == pin); // check if entered pin matches hardcoded pin
    }

    // deposit function to add money to balance
    // deposit amount if greater than 0
    void deposit(double amount)
    {
        if (amount <= 0)
        {
            cout << "invalid amount deposit must be greater than 0" << endl;
            return;
        }
        balance += amount; // add amount to balance
        cout << "Deposited ₹" << amount << ". New balance: ₹" << balance << "\n";
        ;              // display deposit message
        saveBalance(); // save updated balance to
    }

    // withdraw function to deduct money from balance
    // withdraw amount if balance is sufficient

    void withdraw(double amount)
    {
        if (amount <= 100)
        {
            cout << "invalid amount . withdraw must be greater than 100" << endl;
        }
        else if (amount > balance)
        {
            cout << "insufficient amount in balance" << endl;
        }
        else
        {
            balance -= amount;                                                                      // deduct amount from balance
            cout << "withdrwal of ₹" << amount << " successful. New balance: ₹" << balance << "\n"; // display withdrawal message
            saveBalance();                                                                          // save updated balance to file
        }
    }

    void checkBalance()
    {
        cout << "current balance is ₹" << balance << "\n"; // display current balance
    }
};

// Main function to run the ATM menu system
int main()
{
    ATM atm; // create ATM object
    if (!atm.authenticate())
    { // authenticate user
        cout << "Authentication failed. Exiting...\n";
        return 1; // exit if authentication fails
    }

    int choice;
    double amount;
    do
    {
        // display ATM menu options
        cout << "\n******ATM Menu******:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: (1-4): ";
        cin >> choice; // take user choice input

        switch (choice)
        {
        case 1:
            cout << "enter the amount to deposit: ₹ ";
            cin >> amount;       // take deposit amount input
            atm.deposit(amount); // call deposit function
            break;
        case 2:
            cout << "enter the amount to withdraw: ₹ ";
            cin >> amount;        // take withdraw amount input
            atm.withdraw(amount); // call withdraw function
            break;
        case 3:
            cout << "checking balance...\n";
            atm.checkBalance(); // call check balance function
            break;
        case 4:
            cout << " Thank you for using the ATM. Exiting...\n"; // exit message
            break;
        default:
            cout << "Invalid choice. Please try again.\n"; // handle invalid choice
        }
    } while (choice != 4); // loop until user chooses to exit
    return 0; // return 0 to indicate successful execution
}
