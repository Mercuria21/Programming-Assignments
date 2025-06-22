#include <iostream>
using namespace std;

int cubeElement(int num);

int main() {
    //initial array
    int arr[5] = {1, 2, 3, 4, 5};

    //prints original array
    cout << "Original array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    //cubing the array
    for (int i = 0; i < 5; i++) {
        arr[i] = cubeElement(arr[i]);
    }

    //display cubed array
    cout << "Cubed array: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

int cubeElement(int num) {
    return num * num * num;
}

