#include <iostream>
using namespace std;

float calculateInterest(float principal, float rate, int time);
void displayInterest(float principal, float interest);

int main(){
    float principal, rate;
    int time;
    cout << "Please enter principal: ";
    cin >> principal;

    cout << "Please enter rate: ";
    cin >> rate;

    cout << "Please enter time: ";
    cin >> time;

    float interest = calculateInterest(principal, rate, time);
    displayInterest(principal, interest);
}

float calculateInterest(float principal, float rate, int time){

    float interests;

    return interests =(principal*rate*time)/100;
}
void displayInterest(float principal, float interest){
    cout << "Your principal is: " << principal << '\n';
    cout << "Your interest is: " << interest << '\n';
}
