#include <iostream>
using namespace std;

// Base class
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }
};

class Student : public Person {
protected:
    string institution;

public:
    Student(string n, int a, string inst) : Person(n, a) {
        institution = inst;
    }
};

class GraduateStudent : public Student {
private:
    string degree;
    int yearOfGraduation;

public:
    GraduateStudent(string n, int a, string inst, string deg, int year)
        : Student(n, a, inst) {
        degree = deg;
        yearOfGraduation = year;
    }

    void displayDetails() {
        cout << "Graduate Student Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Institution: " << institution << endl;
        cout << "Degree: " << degree << endl;
        cout << "Year of Graduation: " << yearOfGraduation << endl;
    }
};

int main() {
    GraduateStudent gs("Clara", 24, "University of XYZ", "MSc Computer Science", 2025);
    gs.displayDetails();
    return 0;
}
