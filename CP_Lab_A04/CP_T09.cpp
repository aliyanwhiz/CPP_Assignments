#include <iostream>
using namespace std;

int main() {
    string studentName = "Hina";
    bool passed = true;

    cout << "Student Name: " << studentName << endl;
    cout << "Status: " << (passed ? "Passed" : "Failed") << endl;
    return 0;
}