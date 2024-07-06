#include <iostream>
#include <string>
using namespace std;

void showMenu() {
    cout << "Welcome to the Restaurant!" << endl;
    cout << "Here is our menu:" << endl;
    cout << "1. Burger 🍔 - $5.99" << endl;
    cout << "2. Pizza 🍕 - $8.99" << endl;
    cout << "3. Salad 🥗 - $4.99" << endl;
    cout << "4. Hotdogs 🌭 - $5.59" << endl;
    cout << "5. Sandwich 🥪 - $9.59" << endl;
    cout << "6. Maggie 🍜 - $9.29" << endl;
    cout << "7. Exit" << endl;
}

int main() {
    string name;
    int choice;
    char continueOrder;

    cout << "Hello! What's your name?" << endl;
    getline(cin, name);

    cout << "Nice to meet you, " << name << "!" << endl;

    do {
        showMenu();
        cout << "Please enter the number of the item you want to order: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "You ordered a Burger. That will be $5.99." << endl;
                break;
            case 2:
                cout << "You ordered a Pizza. That will be $8.99." << endl;
                break;
            case 3:
                cout << "You ordered a Salad. That will be $4.99." << endl;
                break;
            case 4:
                cout << "You ordered a Hotdog. That will be $5.59." << endl;
                return 0;
            case 5:
                cout << "You ordered a Sandwich. That will be $9.59." << endl;
                return 0;
            case 6:
                cout << "You ordered a Maggie. That will be $9.29" << endl;
                return 0;
            case 7:
                cout << "Thank you for visiting! Have a great day!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                continue;
        }

        cout << "Would you like to order something else? (y/n): ";
        cin >> continueOrder;
        cin.ignore(); // To ignore the newline character left by cin

    } while (continueOrder == 'y' || continueOrder == 'Y');

    cout << "Thank you for your order, " << name << "! Have a great day!" << endl;

    return 0;
}
