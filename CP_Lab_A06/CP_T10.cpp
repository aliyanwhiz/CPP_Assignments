#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter an initial integer: ";
    cin >> num;

    num += 5;
    cout << "After += 5: " << num << endl;

    num -= 2;
    cout << "After -= 2: " << num << endl;

    num *= 3;
    cout << "After *= 3: " << num << endl;

    num /= 2;
    cout << "After /= 2: " << num << endl;

    return 0;
}