#include <iostream>
#include <string>
using namespace std;

class Person {
    public:
        string name;
        int age;

    Person(string n, int a) {
        name = n;
        age = a;
    }
};

class Employee : public Person {
    public:
        int salary;
        string designation;

    Employee(string n, int a, int s, string d) : Person(n, a) {
        salary = s;
        designation = d;
    }
};

int main() {
    Employee employee1("John Doe", 30, 5000, "Software Engineer");
    cout << "Name: " << employee1.name << endl;
    cout << "Age: " << employee1.age << endl;
    cout << "Salary: " << employee1.salary << endl;
    cout << "Designation: " << employee1.designation << endl;
    return 0;
}

