#include <iostream>
using namespace std;

void checkBooking(int x) {
    if (x == 1) throw 1;
    if (x == 0) throw 'B';
    if (x == -1) throw 5.5;
}

int main() {
    int values[] = {1, 0, -1};
    for (int i = 0; i < 3; i++) {
        try {
            checkBooking(values[i]);
        } catch (...) {
            cout << "Caught exception\n";
        }
    }
    return 0;
}