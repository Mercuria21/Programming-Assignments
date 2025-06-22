#include <iostream>
using namespace std;

class Person{
    public:
    string name;
    int age;
    Person(string n, int a){
        name = n;
        age = a;
    }
};

class Student : public Person{
    public:
    string institution;
    Student(string n, int a, string i) : Person(n, a){
        institution = i;
    }
};

class GraduateStudent : public Student{
    public:
    string degree;
    int yearOfGraduation;
    GraduateStudent(string n, int a, string i, string d, int y) : Student(n, a, i){
        degree = d;
        yearOfGraduation = y;
    }
};

int main(){
    GraduateStudent gs("Clara", 24, "University of XYZ", "MSc Computer Science", 2025);
    cout << "Name: " << gs.name << endl;
    cout << "Age: " << gs.age << endl;
    cout << "Institution: " << gs.institution << endl;
    cout << "Degree: " << gs.degree << endl;
    cout << "Year of Graduation: " << gs.yearOfGraduation << endl;
    return 0;
}