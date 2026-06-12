#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter number: ";
    cin >> num;

    if (num >= 1 && num <= 10) {
        cout << "Small" << endl;
    } else if (num >= 11 && num <= 50) {
        cout << "Medium" << endl;
    } else if (num >= 51 && num <= 100) {
        cout << "Large" << endl;
    } else {
        cout << "Out of Range" << endl;
    }
    return 0;
}