#include <iostream>
using namespace std;

int sumMatrix(int matrix[3][3]);

int main() {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int totalSum = sumMatrix(matrix);
    cout << "The sum of all elements in the matrix is: " << totalSum << endl;

    return 0;
}

int sumMatrix(int matrix[3][3]) {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}
