#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>

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
long long factorial(int n);
void decimalToBinary(int n);
int binaryToDecimal(const string &binary);
int main()
{

    int choice;
    double num1, num2, result;

    cout << fixed << setprecision(4); // Set output precision
    cout << "Welcome to my calculator ! " << endl;
    do
    {
        
        cout << "\nWelcome to Our Scientific Calculator\n";
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
        cout << "11. Factorial\n";
        cout << "12. Decimal To Binary\n";
        cout << "13. Binary To Decimal \n";

        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Exitinggggg...\n";
            break;

        case 1:
        {
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            result = add(num1, num2);
            cout << "Result: " << result << endl;
        }
            break;
        case 2:
        {
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            result = subtract(num1, num2);
            cout << "Result: " << result << endl;
        }
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
        case 11: // New case for factorial
        {
            int n;
            cout << "Enter a non-negative integer: ";
            cin >> n;
            if (n < 0)
            {
                cout << "Error: Factorial is not defined for negative numbers!" << endl;
            }
            else
            {
                cout << "Result: " << factorial(n) << endl;
            }
        }
            break;
        case 12:
        {
            int nn;
            cout << "Enter a Decimal Number: ";
            cin >> nn;
            decimalToBinary(nn);
            cout << endl;
        }
            break;

        case 13:

            // Prompt the user to enter a binary number
        {
            string binary;
            cout << "Enter a binary number: ";
            cin >> binary;

            // Convert binary to decimal
            int decimal = binaryToDecimal(binary);

            // Output the result
            cout << "The decimal equivalent of " << binary << " is " << decimal << endl;
        }
            break;

        
       default :
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}

// Function definitions
double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    if (b != 0)
    {
        return a / b;
    }
    else
    {
        cout << "Error: Division by zero!" << endl;
        return 0;
    }
}

double power(double base, double exponent)
{
    return pow(base, exponent);
}

double squareRoot(double a)
{
    if (a >= 0)
    {
        return sqrt(a);
    }
    else
    {
        cout << "Error: Cannot calculate square root of a negative number!" << endl;
        return 0;
    }
}

double sine(double angle)
{
    return sin(angle);
}

double cosine(double angle)
{
    return cos(angle);
}

double tangent(double angle)
{
    return tan(angle);
}

double logarithm(double a)
{
    if (a > 0)
    {
        return log10(a);
    }
    else
    {
        cout << "Error: Cannot calculate logarithm of a non-positive number!" << endl;
        return 0;
    }
}

long long factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

void decimalToBinary(int n)
{
    std::vector<int> binaryNum;

    // Storing binary number in a vector
    while (n > 0)
    {
        binaryNum.push_back(n % 2);
        n = n / 2;
    }

    // Printing the binary number in reverse order
    for (int i = binaryNum.size() - 1; i >= 0; i--)
        std::cout << binaryNum[i];
}

int binaryToDecimal(const string &binary)
{
    int decimal = 0;
    int length = binary.length();

    // Iterate over the binary string
    for (int i = 0; i < length; ++i)
    {
        // If the character is '1', add the corresponding power of 2 to the decimal value
        if (binary[length - 1 - i] == '1')
        {
            decimal += pow(2, i);
        }
    }

    return decimal;
}
