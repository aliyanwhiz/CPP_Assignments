#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    int accNo;
    double balance;
    string history[10];
    int hCount;
public:
    Account(int a, double b) {
        accNo = a;
        balance = b;
        hCount = 0;
        history[hCount++] = "Created";
    }
    
    virtual void deposit(double amt) {
        if (amt > 0) {
            balance += amt;
            history[hCount++] = "Deposit";
        }
    }
    
    virtual void withdraw(double amt) = 0;
    
    void showStatement() {
        cout << "Acc: " << accNo << " | Balance: Rs." << balance << endl;
        cout << "History:\n";
        for (int i = 0; i < hCount; i++) {
            cout << " - " << history[i] << endl;
        }
    }
};

class SavingAccount : public Account {
    double rate;
public:
    SavingAccount(int a, double b, double r) : Account(a, b) { rate = r; }
    
    void addProfit() {
        balance += balance * rate / 100;
        history[hCount++] = "Profit Added";
    }
    
    void withdraw(double amt) override {
        if (amt <= balance) {
            balance -= amt;
            history[hCount++] = "Withdraw";
        } else {
            cout << "Failed: Low balance\n";
        }
    }
};

class CurrentAccount : public Account {
    double limit;
public:
    CurrentAccount(int a, double b, double l) : Account(a, b) { limit = l; }
    
    void withdraw(double amt) override {
        if (balance - amt >= -limit) {
            balance -= amt;
            history[hCount++] = "Withdraw (Overdraft)";
        } else {
            cout << "Failed: Overdraft limit crossed\n";
        }
    }
};

class StudentAccount : public Account {
    double maxLimit;
public:
    StudentAccount(int a, double b, double m) : Account(a, b) { maxLimit = m; }
    
    void withdraw(double amt) override {
        if (amt <= maxLimit && amt <= balance) {
            balance -= amt;
            history[hCount++] = "Withdraw";
        } else {
            cout << "Failed: Limit exceeded\n";
        }
    }
};

int main() {
    SavingAccount s(101, 20000, 5);
    s.deposit(5000);
    s.addProfit();
    s.withdraw(3000);
    s.showStatement();
    
    cout << endl;
    
    CurrentAccount c(102, 5000, 2000);
    c.withdraw(6000);
    c.showStatement();
    
    return 0;
}