#include <iostream>
using namespace std;

int main() {
    int marks, attendance;
    cout << "Enter marks: "; cin >> marks;
    cout << "Enter attendance %: "; cin >> attendance;

    if (marks >= 80 && attendance >= 75)
        cout << "Student is Eligible" << endl;
    else
        cout << "Student is Not Eligible" << endl;

    return 0;
}