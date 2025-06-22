#include <iostream>
using namespace std;

class Customer{
    public:
    string customerName;
    Customer(string name){
        customerName = name;
    }
};

class Account : public Customer{
    public:
    int accountBalance;
    Account(string name, int balance) : Customer(name){
        accountBalance = balance;
    }
};

class Loan{
    public:
    int loanAmount;
    Loan(int amount){
        loanAmount = amount;
    }
};

class BankSystem : public Account, public Loan{
    public:
    int totalBalance;
    BankSystem(string name, int balance, int amount) : Account(name, balance), Loan(amount){
        totalBalance = accountBalance + loanAmount;;
    }

    void display(){
        cout<<"Customer Name: " <<customerName<<endl;
        cout<<"Account Balance: " <<accountBalance<<endl;
        cout<<"Loan Amount: " <<loanAmount<<endl;
        cout<<"Total Balance: " <<totalBalance<<endl;
    }
};

int main(){
    BankSystem b1("John Doe", 5000, 15000);
    b1.display();
    return 0;
}