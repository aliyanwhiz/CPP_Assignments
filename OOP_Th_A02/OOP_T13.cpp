#include <iostream>
using namespace std;

class InvalidWithdrawal {
public:
    string getMessage() const {
        return "Error: Withdrawal amount exceeds available balance!";
    }
};

class ATM {
    double balance;
public:
    ATM(double b) { balance = b; }
    void withdraw(double amount) {
        if (amount > balance) {
            throw InvalidWithdrawal();
        }
        balance -= amount;
        cout << balance << endl;
    }
};

int main() {
    ATM myAtm(10000);
    try {
        myAtm.withdraw(12000);
    } catch (InvalidWithdrawal& e) {
        cout << e.getMessage() << endl;
    }
    return 0;
}