#include <iostream>
using namespace std;

class Rectangle {
    private: 
        int length;
        int width;

    public:
        Rectangle() {
            length = 1;
            width = 1;
        }

        Rectangle(int l, int w) {
            length = l;
            width = w;
        }

        int calc_area() {
            return length * width;
        }

    void display() {
        cout << "length: " << length << ", width: " << width << endl;
    }
};

int main() {
    Rectangle rect1;
    cout << "Default Rectangle: " << endl;
    rect1.display();
    cout << "area: " << rect1.calc_area() << endl;
    
    Rectangle rect2(5, 3);
    cout << "PaRameterized Rectangle: " << endl;
    rect2.display();
    cout << "area: " << rect2.calc_area() << endl;

    return 0;
}