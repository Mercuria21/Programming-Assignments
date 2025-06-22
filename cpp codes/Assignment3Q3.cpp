#include <iostream>
#include <limits>

using namespace std;

void display_stream_states() {
    // Display stream states
    cout << "Stream states after error: " << endl;
    cout << "cin.rdstate(): " << cin.rdstate() << endl;
    cout << "cin.eof(): " << cin.eof() << endl;
    cout << "cin.fail(): " << cin.fail() << endl;
    cout << "cin.bad(): " << cin.bad() << endl;
    cout << "cin.good(): " << cin.good() << endl;
}

void clear_stream() {
    // Clear stream
    cin.clear();

    // Ignore rest of line
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Retry
    cout << "\nClearing error and retrying..." << endl;
}

void process_withdrawal(int amount) {
    // Process withdrawal
    cout << "Please take your case: $" << amount << endl;
}

void atm() {
    int amount;
    cout << "Welcome to the ATM System" << endl;

    while (true) {
        // Get user input
        cout << "\nEnter amount to withdraw (or -1 to exit): ";
        cin >> amount;

        // Check for errors
        if (cin.fail()){
            cout << "Bad input detected!" << endl;
            display_stream_states();
            clear_stream();
            continue;
        }

        // Check if user wants to exit
        if (amount == -1) {
            cout << "Thank you for using our ATM!" << endl;
            break;
        }

        // Check if amount is valid
        if (amount <= 0) {
            cout << "Please enter a positive amount greater than 0" << endl;
            continue;
        }
        process_withdrawal(amount);
    }
}

int main() {
    atm();
    return 0;
}
