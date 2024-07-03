#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Item {
public:
    string name;
    double price;
    int quantity;

    Item(string n, double p, int q) : name(n), price(p), quantity(q) {}
};

void showMenu() {
    cout << "Grocery Shop Menu\n";
    cout << "1. Apple - 25.50\n";
    cout << "2. Banana - 10.20\n";
    cout << "3. Orange - 50.80\n";
    cout << "4. Milk - 30.00\n";
    cout << "5. Bread - 20.00\n";
    cout << "6. Don't Want to Buy \n";
}

int main() {
    vector<Item> cart;
    int choice;
    int quantity;
    double total = 0.0;

    while (true) {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 6) {
            break;
        }

        cout << "Enter quantity: ";
        cin >> quantity;

        switch (choice) {
            case 1:
                cart.push_back(Item("Apple",25.50, quantity));
                break;
            case 2:
                cart.push_back(Item("Banana", 10.20, quantity));
                break;
            case 3:
                cart.push_back(Item("Orange", 50.80, quantity));
                break;
            case 4:
                cart.push_back(Item("Milk", 30.00, quantity));
                break;
            case 5:
                cart.push_back(Item("Bread", 20.00, quantity));
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                continue;
        }

        cout << "Item added to cart.\n";
    }

    cout << "\nBilling Summary:\n";
    cout << left << setw(10) << "Item"
         << right << setw(10) << "Quantity"
         << right << setw(10) << "Price"
         << right << setw(10) << "Total\n";
//left: A manipulator that sets the output to be left-aligned. It affects how the next values will be aligned in their respective fields.
//right: A manipulator that sets the output to be right-aligned. It affects how the next values will be aligned in their respective fields.


    for (const auto& item : cart) {
        double itemTotal = item.price * item.quantity;
        total += itemTotal;
        cout << left << setw(10) << item.name
             << right << setw(10) << item.quantity
             << right << setw(10) << item.price
             << right << setw(10) << itemTotal << "\n";
    }

    cout << "\nTotal Bill : Rs " << total << "\n";

    return 0;
}
