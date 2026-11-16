#include <iostream>
using namespace std;

class Patient {
protected:
    int id;
    string name;
public:
    Patient(int i, string n) { id = i; name = n; }
    friend class BillingDesk;
    friend void compareBills(const class ERPatient& e, const class RegPatient& r);
};

class ERPatient : public Patient {
    int hours;
    double rate;
public:
    ERPatient(int i, string n, int h, double r) : Patient(i, n) {
        hours = h; rate = r;
    }
    double getBill() const { return hours * rate; }
    friend class BillingDesk;
    friend void compareBills(const ERPatient& e, const RegPatient& r);
};

class RegPatient : public Patient {
    int visits;
    double fee;
public:
    RegPatient(int i, string n, int v, double f) : Patient(i, n) {
        visits = v; fee = f;
    }
    double getBill() const { return visits * fee; }
    friend class BillingDesk;
    friend void compareBills(const ERPatient& e, const RegPatient& r);
};

class BillingDesk {
public:
    void issueInvoice(const ERPatient& e) {
        cout << "Invoice #" << e.id << " " << e.name << ": Rs. " << e.getBill() << endl;
    }
    void issueInvoice(const RegPatient& r) {
        cout << "Invoice #" << r.id << " " << r.name << ": Rs. " << r.getBill() << endl;
    }
};

void compareBills(const ERPatient& e, const RegPatient& r) {
    cout << "Higher bill: " << e.name << " (" << e.getBill() << " vs " << r.getBill() << ")\n";
}

int main() {
    ERPatient ep(11, "Aliyan Ahmed", 5, 2000);
    RegPatient rp(12, "Hamza", 4, 1000);
    BillingDesk desk;
    desk.issueInvoice(ep);
    desk.issueInvoice(rp);
    compareBills(ep, rp);
    return 0;
}