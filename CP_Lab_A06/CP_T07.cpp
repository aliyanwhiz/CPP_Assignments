#include <iostream>
using namespace std;

int main() {
    int units;
    cout << "Enter units consumed: ";
    cin >> units;

    if (units <= 100) cout << "Category: Low" << endl;
    else if (units <= 300) cout << "Category: Medium" << endl;
    else cout << "Category: High" << endl;

    return 0;
}