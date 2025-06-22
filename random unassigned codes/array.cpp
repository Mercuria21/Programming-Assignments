#include <iostream>
using namespace std;

int changeValue(int);

int main() {
    int arr[3] = {0, 0, 0}, i, sum = 0;

    for (i = 0; i < 3; i++) {
        cout << "\nOld value for arr[" << i << "]: " << arr[i] << endl;

        arr[i] = changeValue(arr[i]);

        cout << "New value for arr[" << i << "]: " << arr[i] << endl;

        sum = sum + arr[i];
    }

    cout << "\nTotal: " << sum << endl;
    return 0;
}

int changeValue(int value) {
    cout << "Enter new value: ";
    cin >> value;
    return value;
}
