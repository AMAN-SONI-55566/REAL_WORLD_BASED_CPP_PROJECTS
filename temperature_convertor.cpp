// program to convert temperatures between Celsius, Fahrenheit, and Kelvin
#include <iostream>
#include <iomanip>

using namespace std;

// Constants
const double KELVIN_OFFSET = 273.15;

// Function Declarations
double CelsiusToFahrenheit(double celsius);
double FahrenheitToCelsius(double fahrenheit);
double CelsiusToKelvin(double celsius);
double KelvinToCelsius(double kelvin);
double FahrenheitToKelvin(double fahrenheit);
double KelvinToFahrenheit(double kelvin);
void DisplayMenu();

int main()
{
    int choice;
    double input_temp;

    cout << fixed << setprecision(2);

    do
    {
        DisplayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter temperature in Celsius: ";
            cin >> input_temp;
            cout << "Fahrenheit: " << CelsiusToFahrenheit(input_temp) << " °F\n";
            break;

        case 2:
            cout << "Enter temperature in Fahrenheit: ";
            cin >> input_temp;
            cout << "Celsius: " << FahrenheitToCelsius(input_temp) << " °C\n";
            break;

        case 3:
            cout << "Enter temperature in Celsius: ";
            cin >> input_temp;
            cout << "Kelvin: " << CelsiusToKelvin(input_temp) << " K\n";
            break;

        case 4:
            cout << "Enter temperature in Kelvin: ";
            cin >> input_temp;
            cout << "Celsius: " << KelvinToCelsius(input_temp) << " °C\n";
            break;

        case 5:
            cout << "Enter temperature in Fahrenheit: ";
            cin >> input_temp;
            cout << "Kelvin: " << FahrenheitToKelvin(input_temp) << " K\n";
            break;

        case 6:
            cout << "Enter temperature in Kelvin: ";
            cin >> input_temp;
            cout << "Fahrenheit: " << KelvinToFahrenheit(input_temp) << " °F\n";
            break;

        case 0:
            cout << "Exiting the program. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }

        cout << "\n";

    } while (choice != 0);

    return 0;
}

// Function Definitions

// Converts Celsius to Fahrenheit
double CelsiusToFahrenheit(double celsius)
{
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Converts Fahrenheit to Celsius
double FahrenheitToCelsius(double fahrenheit)
{
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

// Converts Celsius to Kelvin
double CelsiusToKelvin(double celsius)
{
    return celsius + KELVIN_OFFSET;
}

// Converts Kelvin to Celsius
double KelvinToCelsius(double kelvin)
{
    return kelvin - KELVIN_OFFSET;
}

// Converts Fahrenheit to Kelvin
double FahrenheitToKelvin(double fahrenheit)
{
    return CelsiusToKelvin(FahrenheitToCelsius(fahrenheit));
}

// Converts Kelvin to Fahrenheit
double KelvinToFahrenheit(double kelvin)
{
    return CelsiusToFahrenheit(KelvinToCelsius(kelvin));
}

// Displays the conversion menu
void DisplayMenu()
{
    cout << "===== Temperature Converter =====\n";
    cout << "1. Celsius to Fahrenheit\n";
    cout << "2. Fahrenheit to Celsius\n";
    cout << "3. Celsius to Kelvin\n";
    cout << "4. Kelvin to Celsius\n";
    cout << "5. Fahrenheit to Kelvin\n";
    cout << "6. Kelvin to Fahrenheit\n";
    cout << "0. Exit\n";
    cout << "Choose an option (0-6): ";
}
