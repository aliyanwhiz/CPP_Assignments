#include <iostream>
using namespace std;

int main() {
    double salary;
    cout << "Enter salary: ";
    cin >> salary;

    if (salary >= 50000) {
        cout << "Bonus: 5000" << endl;
    } else if (salary >= 30000) {
        cout << "Bonus: 3000" << endl;
    } else if (salary >= 20000) {
        cout << "Bonus: 2000" << endl;
    } else {
        cout << "No Bonus" << endl;
    }
    return 0;
}