#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a five-digit number: ";
    cin >> n;

    bool isSilver = true;
    if (n < 10000 || n > 99999) 
        isSilver = false;

    int zeroCount = 0;
    int temp = n;
    while (temp > 0) {
        int digit = temp % 10;
        if (digit == 0)
            zeroCount++;
        temp /= 10;
    }

    if (isSilver && zeroCount >= 2) {
        cout << n << " is a silver number\n";
    } else {
        cout << n << " is not a silver number\n";
    }
    return 0;
}
