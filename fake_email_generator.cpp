#include <iostream>
#include <vector>
#include <cstdlib> // for rand(), srand()
#include <ctime>   // for time()
#include <string>

using namespace std;

// Function to generate a random email ID
string generateRandomEmail(const vector<string> &names, const vector<string> &domains)
{
    // Select a random name
    string name = names[rand() % names.size()];

    // Optional suffix: either empty, a number, or a tech tag
    string suffix;
    int suffixType = rand() % 3;
    if (suffixType == 1)
    {
        suffix = to_string(rand() % 1000); // number suffix
    }
    else if (suffixType == 2)
    {
        suffix = ".tech";
        // Optionally add number after .tech
        if (rand() % 2 == 0)
        {
            suffix += to_string(rand() % 100);
        }
    }
    // Combine name + suffix
    string localPart = name + suffix;

    // Select a random domain
    string domain = domains[rand() % domains.size()];

    // Form the email
    string email = localPart + "@" + domain;

    return email;
}

int main()
{
    // Seed(starting point) random number generator
    srand(static_cast<unsigned int>(time(nullptr))); 

    // Sample data
    vector<string> names = {"aman", "rahul", "anisha", "avinash", "neha", "tisha"};
    vector<string> domains = {"gmail.com", "yahoo.com", "outlook.com", "hotmail.com"};

    // Generate and print 5 random emails
    cout << "Random Email IDs:\n";
    for (int i = 0; i < 5; ++i)
    {
        cout << generateRandomEmail(names, domains) << endl;
    }

    return 0;
}
