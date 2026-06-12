#include <iostream>
using namespace std;

int main() {
    string name = "Ali";
    int rollNumber = 101;
    double marks = 88.5;
    char grade = 'A';
    bool isPresent = true;

    cout << "Name: " << name << endl;
    cout << "Roll Number: " << rollNumber << endl;
    cout << "Marks: " << marks << endl;
    cout << "Grade: " << grade << endl;
    cout << "Present: " << (isPresent ? "Yes" : "No") << endl;
    return 0;
}