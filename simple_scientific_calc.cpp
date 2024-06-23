#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Function prototypes
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double base, double exponent);
double squareRoot(double a);
double sine(double angle);
double cosine(double angle);
double tangent(double angle);
double logarithm(double a);

int main() {
    
    int choice;
    double num1, num2, result;

    cout << fixed << setprecision(4);  // Set output precision
    cout << "Welcome to my calculator "<< endl;
    do {
        cout << "\nScientific Calculator\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Power\n";
        cout << "6. Square Root\n";
        cout << "7. Sine\n";
        cout << "8. Cosine\n";
        cout << "9. Tangent\n";
        cout << "10. Logarithm (base 10)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                result = add(num1, num2);
                cout << "Result: " << result << endl;
                break;
            case 2:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                result = subtract(num1, num2);
                cout << "Result: " << result << endl;
                break;
            case 3:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                result = multiply(num1, num2);
                cout << "Result: " << result << endl;
                break;
            case 4:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                result = divide(num1, num2);
                cout << "Result: " << result << endl;
                break;
            case 5:
                cout << "Enter base and exponent: ";
                cin >> num1 >> num2;
                result = power(num1, num2);
                cout << "Result: " << result << endl;
                break;
            case 6:
                cout << "Enter a number: ";
                cin >> num1;
                result = squareRoot(num1);
                cout << "Result: " << result << endl;
                break;
            case 7:
                cout << "Enter angle in radians: ";
                cin >> num1;
                result = sine(num1);
                cout << "Result: " << result << endl;
                break;
            case 8:
                cout << "Enter angle in radians: ";
                cin >> num1;
                result = cosine(num1);
                cout << "Result: " << result << endl;
                break;
            case 9:
                cout << "Enter angle in radians: ";
                cin >> num1;
                result = tangent(num1);
                cout << "Result: " << result << endl;
                break;
            case 10:
                cout << "Enter a number: ";
                cin >> num1;
                result = logarithm(num1);
                cout << "Result: " << result << endl;
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 0);

    return 0;
}

// Function definitions
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        cout << "Error: Division by zero!" << endl;
        return 0;
    }
}

double power(double base, double exponent) {
    return pow(base, exponent);
}

double squareRoot(double a) {
    if (a >= 0) {
        return sqrt(a);
    } else {
        cout << "Error: Cannot calculate square root of a negative number!" << endl;
        return 0;
    }
}

double sine(double angle) {
    return sin(angle);
}

double cosine(double angle) {
    return cos(angle);
}

double tangent(double angle) {
    return tan(angle);
}

double logarithm(double a) {
    if (a > 0) {
        return log10(a);
    } else {
        cout << "Error: Cannot calculate logarithm of a non-positive number!" << endl;
        return 0;
    }
}
