#include <iostream>
using namespace std;

class Employee {
protected:
    string name;
    double salary;
public:
    Employee(string n, double s) {
        name = n;
        salary = s;
    }
    void showEmployee() {
        cout << name << " " << salary << endl;
    }
};

class LoanOfficer : public Employee {
    double loanLimit;
public:
    LoanOfficer(string n, double s, double limit) : Employee(n, s) {
        loanLimit = limit;
    }
    void processLoan() {
        cout << loanLimit << endl;
    }
};

int main() {
    LoanOfficer lo("Aliyan Ahmed", 90000, 2000000);
    lo.showEmployee();
    lo.processLoan();
    return 0;
}