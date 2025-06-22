#include <iostream>
using namespace std;

void displayMenu();
double calcFunc(double num1, double num2, char opt);
void displayOutput(double result);

int main() {
    double num1, num2, result;
    char opt;

    displayMenu();

    cout << "Please enter your option (1-4): ";
    cin >> opt;

    if (opt < '1' || opt > '4') {
        cout << "Invalid option. Please restart the program.\n";
        return 1;
    }

    cout << "Please enter first number: ";
    cin >> num1;

    cout << "Please enter second number: ";
    cin >> num2;

    result = calcFunc(num1, num2, opt);
    displayOutput(result);

    return 0;
}

void displayMenu() {
    cout << "Welcome to the calculator!\n";
    cout << "Choose your desired operation: \n";
    cout << "1. Summation\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
}

double calcFunc(double num1, double num2, char opt) {
    switch (opt) {
        case '1':
            return num1 + num2;
        case '2':
            return num1 - num2;
        case '3':
            return num1 * num2;
        case '4':
            if (num2 != 0) {
                return num1 / num2;
            } else {
                cout << "Error: Division by zero is not allowed.\n";
                return 0;
            }
        default:
            cout << "Invalid operation.\n";
            return 0;
    }
}

void displayOutput(double result) {
    cout << "The result is: " << result << endl;
}
