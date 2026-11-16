#include <iostream>
using namespace std;

class LoanAccount {
protected:
    int accNo;
    double outstanding;
public:
    LoanAccount(int a, double out) {
        accNo = a;
        outstanding = out;
    }
    friend class LoanAuditor;
};

class HomeLoan : public LoanAccount {
    double rate;
public:
    HomeLoan(int a, double out, double r) : LoanAccount(a, out) {
        rate = r;
    }
    friend class LoanAuditor;
};

class LoanAuditor {
public:
    void printStatement(const HomeLoan& h) {
        double interest = h.outstanding * h.rate / 100.0;
        cout << "Account: " << h.accNo << " | Outstanding Loan: " << h.outstanding << " | Annual Interest: " << interest << endl;
    }
    void checkLimit(const LoanAccount& l, double limit) {
        if (l.outstanding > limit) {
            cout << "Loan exceeds the limit\n";
        }
    }
};

int main() {
    HomeLoan hl(7001, 500000, 8.0);
    LoanAuditor auditor;
    auditor.printStatement(hl);
    auditor.checkLimit(hl, 400000);
    return 0;
}