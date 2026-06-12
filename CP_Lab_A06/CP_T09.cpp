#include <iostream>
using namespace std;

int main() {
    int choice;
    cout << "--- Menu ---" << endl;
    cout << "1 -> Burger\n2 -> Pizza\n3 -> Sandwich" << endl;
    cout << "Select option: ";
    cin >> choice;

    switch (choice) {
        case 1: cout << "Selected Food: Burger"; break;
        case 2: cout << "Selected Food: Pizza"; break;
        case 3: cout << "Selected Food: Sandwich"; break;
        default: cout << "Invalid Selection";
    }
    cout << endl;
    return 0;
}