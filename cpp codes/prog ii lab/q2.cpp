#include <iostream>
using namespace std;

//function prototyping
void getMarks(int &mark1, int &mark2, int &mark3);
char calculateGrade(int avg);
void displayResults(int avg, char grade);

int main(){
    int mark1, mark2, mark3, avg;

    getMarks(mark1, mark2, mark3);
    avg = (mark1+mark2+mark3)/3;

    char grade = calculateGrade(avg);
    displayResults(avg, grade);
}

void getMarks(int &mark1, int &mark2, int &mark3){
    //getting marks
    cout << "Please enter first marks: ";
    cin >> mark1;

    cout << "Please enter second marks: ";
    cin >> mark2;

    cout << "Please enter third marks: ";
    cin >> mark3;
}
char calculateGrade(int avg){
    //if-else for getting grade
    if (avg >= 90) return 'A';
    else if (avg >= 80) return 'B';
    else if (avg >= 70) return 'C';
    else if (avg >= 60) return 'D';
    else return 'F';
}
void displayResults(int avg, char grade){
    //displaying grade and average mark
    cout << "\nYour average mark is " << avg;
    cout << "\nYour grade is " << grade << '\n';
}
