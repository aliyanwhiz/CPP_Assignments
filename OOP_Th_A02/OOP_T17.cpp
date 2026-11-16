#include <iostream>
using namespace std;

int main() {
    string customerName = "Aliyan Ahmed";
    double amount = -500;
    try {
        if (amount <= 0) {
            throw "Error: Invalid payment amount!";
        }
        cout << "Payment Successful!\n";
    } catch (const char* msg) {
        cout << msg << endl;
    }
    return 0;
}