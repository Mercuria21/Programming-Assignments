#include <iostream>
using namespace std;

class Student {
protected:
    string name;

public:
    Student(string n) {
        name = n;
    }
};

class Exam : public Student {
protected:
    int marks;

public:
    Exam(string n, int m) : Student(n) {
        marks = m;
    }
};

class Sports {
protected:
    int score;

public:
    Sports(int s) {
        score = s;
    }
};

class Result : public Exam, public Sports {
public:
    Result(string n, int m, int s) : Exam(n, m), Sports(s) {}

    void display() {
        cout << "Student Name: " << name << endl;
        cout << "Marks Obtained: " << marks << endl;
        cout << "Sports Score: " << score << endl;
        cout << "Total Marks and Score: " << (marks + score) << endl;
    }
};

int main() {
    Result r("Emma", 85, 40);
    r.display();
    return 0;
}
