#include <iostream>
using namespace std;

int main() {
    int n, sum = 0, temp, remainder, digits = 0;
    cout << "Enter a number: ";
    cin >> n;

    temp = n;
    while (temp != 0) {
        digits++;
        temp /= 10;
    }

    temp = n;
    while (temp != 0) {
        remainder = temp % 10;
        int power = 1;
        for (int i = 0; i < digits; i++) {
            power *= remainder;
        }
        sum += power;
        temp /= 10;
    }

    if (sum == n)
        cout << n << " is an Armstrong number." << endl;
    else
        cout << n << " is not an Armstrong number." << endl;

    return 0;
}