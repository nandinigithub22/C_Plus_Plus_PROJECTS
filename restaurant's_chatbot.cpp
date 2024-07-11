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
    cout << "7. Pasta 🍝 - $7.49" << endl;
    cout << "8. Sushi 🍣 - $12.99" << endl;
    cout << "9. Steak 🥩 - $15.99" << endl;
    cout << "10. Tacos 🌮 - $6.99" << endl;
    cout << "11. Ice Cream 🍦 - $3.99" << endl;
    cout << "12. Exit" << endl;
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
                break;
            case 5:
                cout << "You ordered a Sandwich. That will be $9.59." << endl;
                break;
            case 6:
                cout << "You ordered a Maggie. That will be $9.29." << endl;
                break;
            case 7:
                cout << "You ordered a Pasta. That will be $7.49." << endl;
                break;
            case 8:
                cout << "You ordered a Sushi. That will be $12.99." << endl;
                break;
            case 9:
                cout << "You ordered a Steak. That will be $25.99." << endl;
                break;
            case 10:
                cout << "You ordered Tacos. That will be $6.99." << endl;
                break;
            case 11:
                cout << "You ordered Ice Cream. That will be $3.99." << endl;
                break;
            case 12:
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
