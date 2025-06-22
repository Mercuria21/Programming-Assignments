#include <iostream>
#include <iomanip>
using namespace std;

class Product {
    public:
    string name;

    void input() {
        cout << "Enter name of product" << ": ";
        getline(cin, name);
        cin.ignore();
    }
};

class PricedProduct : public Product {
    public:
    double price;

    void input() {
        Product::input();

        cout << "Enter price of product" << ": ";
        cin >> price;
        cin.ignore();
    }

    void display() {
        cout << fixed << setprecision(2) <<"Product: " << name << ", Price: " << price << endl;
    }
};

int main(){
    PricedProduct product[2];

    for(int i = 0; i < 2; i++) {
        product[i].input();
    }

    product[0].display();
    product[1].display();

    return 0;
}
