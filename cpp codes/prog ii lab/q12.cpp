#include <iostream>
#include <string>
using namespace std;

class person{
private:
    string name;
    int age;
public:
    void display_info(){
    cout << name;
    cout << age;
    }

    void setName(string myName){
    name = myName;
    }

    void setAge(int myAge){
        if (age < 1 || age > 100){
            cout << "Invalid Age";
    }
        else{
            age = myAge;
    }
    }

};

int main(){
    person p;
    p.setName("Adam\n");
    p.setAge(20);

    cout << p.setName();
    cout << p.setAge();

}
