#include <iostream>
using namespace std;

class CommAcc;

class ResAcc {
    double bill;
public:
    ResAcc(double b) { bill = b; }
    friend double getCombinedBill(const ResAcc& r, const CommAcc& c);
};

class CommAcc {
    double bill;
public:
    CommAcc(double b) { bill = b; }
    friend double getCombinedBill(const ResAcc& r, const CommAcc& c);
};

double getCombinedBill(const ResAcc& r, const CommAcc& c) {
    return r.bill + c.bill;
}

int main() {
    ResAcc res(4500);
    CommAcc com(12500);
    cout << "Combined bill: " << getCombinedBill(res, com) << endl;
    return 0;
}