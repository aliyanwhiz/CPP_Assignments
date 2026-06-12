#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char op;

    cout << "Enter number 1: ";
    cin >> num1;
    cout << "Enter number 2: ";
    cin >> num2;
    cout << "Enter operation (+, -, *, /): ";
    cin >> op;

    if (op == '+') {
        cout << "Result: " << num1 + num2 << endl;
    } else if (op == '-') {
        cout << "Result: " << num1 - num2 << endl;
    } else if (op == '*') {
        cout << "Result: " << num1 * num2 << endl;
    } else if (op == '/') {
        if (num2 != 0) {
            cout << "Result: " << num1 / num2 << endl;
        } else {
            cout << "Error: Division by zero!" << endl;
        }
    } else {
        cout << "Invalid operation!" << endl;
    }
    return 0;
}