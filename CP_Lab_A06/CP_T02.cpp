#include <iostream>
using namespace std;

int main() {
    int marks;
    cout << "Enter student marks: ";
    cin >> marks;

    if (marks >= 50) cout << "Pass" << endl;
    else cout << "Fail" << endl;

    return 0;
}