// this code generates a receipt for items purchased, including GST calculation.
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main()
{

    // vector<string> items;
    // vector<double> prices;
    // string name;
    // double price;
    // char ch;

    // using both vector and pair to store item names and prices
    vector<pair<string, double>> items;
    string name;
    double price;
    char ch;

    do
    {
        cout << "Item name: ";
        cin >> ws;
        getline(cin, name);
        cout << "Price: ";
        cin >> price;
        // items.push_back(name); // if using separate vectors for names and prices
        items.emplace_back(name, price); // directly adding a pair to the vector
        cout << "Add more? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    double total = 0;
    cout << "\nReceipt:\n";
    cout << left << setw(20) << "Item" << right << setw(10) << "Price\n";
    cout << "--------------------------\n";

    for (auto &item : items) // auto is used to automatically deduce the type of item
    // we didn't use range-based for loop here because we need to modify the item
    // if we were using separate vectors, we would use a for loop like this:
    // for (size_t i = 0; i < items.size(); ++i) {
    //     cout << left << setw(20) << items[i].first << right << setw(10) << fixed << setprecision(2) << items[i].second << "\n";
    //     total += items[i].second;
    // }

    {
        cout << left << setw(20) << item.first << right << setw(10) << fixed << setprecision(2) << item.second << "\n";
        total += item.second;
    }

    double gst = total * 0.18;
    cout << "--------------------------\n";
    cout << left << setw(20) << "Total" << right << setw(10) << total << "\n";
    cout << left << setw(20) << "GST (18%)" << right << setw(10) << gst << "\n";
    cout << left << setw(20) << "Final Amount" << right << setw(10) << (total + gst) << "\n";

    return 0;
}
