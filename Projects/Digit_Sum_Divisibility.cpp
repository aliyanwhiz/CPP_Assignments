#include <iostream>
using namespace std;   

int main() {
    int n;
    int d1, d2, d3, d4, d5;
    cout << "Enter a 5-digit number: ";
    cin >> n;

    if (n >= 10000 && n <= 99999) {
        d1 = n / 10000;
        d2 = (n / 1000) % 10;
        d3 = (n / 100) % 10;
        d4 = (n / 10) % 10;
        d5 = n % 10;
        int sum = d1 + d2 + d3 + d4 + d5;
        if (sum % 3 == 0) {
            cout << n << " (sum of digits: " << sum << ") is divisible by 3." << endl;
        } else {
            cout << n << " (sum of digits: " << sum << ") is not divisible by 3." << endl;
        }
    } else {
        cout << "Please enter a valid 5-digit number." << endl;
    }

    return 0;
}