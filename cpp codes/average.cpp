#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int num1=0, num2=0, num3=0;
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Enter third number: ";
    cin >> num3;

    int sum = num1 + num2 + num3;
    int avg = sum/3;
    cout << "Sum of three numbers: "
    << avg;

}
