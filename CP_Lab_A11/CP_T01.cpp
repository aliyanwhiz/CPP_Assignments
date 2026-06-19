#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int rollNumber;
    int age;
    double cgpa;
};

int main() {
    Student students[3];

    for (int i = 0; i < 3; i++) {
        cout << "Enter details for Student " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Roll Number: ";
        cin >> students[i].rollNumber;
        cout << "Age: ";
        cin >> students[i].age;
        cout << "CGPA: ";
        cin >> students[i].cgpa;
        cout << endl;
    }
    
    cout << "--- Student Information ---" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Student " << i + 1 << " Name: " << students[i].name 
             << " Roll No: " << students[i].rollNumber 
             << " Age: " << students[i].age 
             << " CGPA: " << students[i].cgpa << endl;
    }

    return 0;
}