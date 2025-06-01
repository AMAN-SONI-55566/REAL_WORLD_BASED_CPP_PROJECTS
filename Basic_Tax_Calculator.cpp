// basic tax calculator
#include <iostream>
#include <iomanip>
using namespace std;

// definine income range limits and tax rates
const double INCOME_RANGE_1 = 10000.0; // Income up to $10,000
const double INCOME_RANGE_2 = 20000.0; // Income from $10,001 to $20,000
const double INCOME_RANGE_3 = 30000.0; // Income from $20,001 to $30,000

const double TAX_RATE_1 = 0.10; // 10% for income up to $10,000
const double TAX_RATE_2 = 0.15; // 15% for income from $10,001 to $20,000
const double TAX_RATE_3 = 0.20; // 20% for income above $20,000

double calculateTax(double income)
{
    double tax = 0.0; // Initialize tax to zero

    // Calculate tax based on income ranges
    if (income <= INCOME_RANGE_1)
    {
        tax = 0.0; // No tax for income up to $10,000
    }
    else if (income <= INCOME_RANGE_2)
    {
        tax = (income - INCOME_RANGE_1) * TAX_RATE_2; // 15% tax for income from $10,001 to $20,000
    }
    else if (income <= INCOME_RANGE_3)
    {
        tax = (income - INCOME_RANGE_2) * TAX_RATE_3 + (INCOME_RANGE_2 - INCOME_RANGE_1) * TAX_RATE_2; // 20% tax for income from $20,001 to $30,000
    }
    else
    {
        tax = (income - INCOME_RANGE_3) * TAX_RATE_3 + (INCOME_RANGE_3 - INCOME_RANGE_2) * TAX_RATE_2 + (INCOME_RANGE_2 - INCOME_RANGE_1) * TAX_RATE_2; // Additional tax for income above $30,000
    }

    return tax; // Return the calculated tax
}

int main()
{
    double income;

    // Prompt user for income input
    cout << "Enter your annual income: $";
    cin >> income;

    // Validate input
    if (income < 0)
    {
        cout << "Income cannot be negative." << endl;
        return 1; // Exit with error code
    }

    // Calculate tax
    double tax = calculateTax(income);

    // Display the result
    cout << fixed << setprecision(2); // Set output format to two decimal places
    cout << "Your calculated tax is: $" << tax << endl;

    return 0; // Exit successfully
}

// readme: This code implements a basic tax calculator in C++. It calculates the tax based on predefined income ranges and corresponding tax rates. The user is prompted to enter their annual income, and the program computes the tax based on the specified rules. The output is formatted to display two decimal places for clarity. The code includes input validation to ensure that negative income values are not accepted.
// The program uses the C++14 standard and includes necessary headers for input/output operations