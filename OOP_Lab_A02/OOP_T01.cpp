#include <iostream>
using namespace std;

class Person {
private:
    string name;
public:
    Person(string n = "") { name = n; }
    void setName(string n) { name = n; }
    void display() const {
        cout << "Name: " << name << endl;
    }
};

class Employee : public Person {
private:
    const int empId;
    double salary;
    static int totalEmployees;
public:
    Employee(string n = "", double s = 0) : Person(n), empId(100 + totalEmployees), salary(s) {
        totalEmployees++;
    }
    
    void setData(string n, double s) {
        setName(n);
        salary = s;
    }
    
    static int getTotalEmployees() {
        return totalEmployees;
    }
    
    friend class PayrollOfficer;
    friend bool isPaidMore(const Employee& a, const Employee& b);
};

int Employee::totalEmployees = 0;

class Manager : public Employee {
private:
    double bonus;
public:
    Manager(string n = "", double s = 0, double b = 0) : Employee(n, s), bonus(b) {}
    
    friend class PayrollOfficer;
};

class PayrollOfficer {
public:
    double calculatePay(const Employee& e) const {
        return e.salary;
    }
    
    double calculatePay(const Manager& m) const {
        return m.salary + m.bonus;
    }
};

bool isPaidMore(const Employee& a, const Employee& b) {
    return a.salary > b.salary;
}

int main() {
    Employee staff[3];
    staff[0].setData("Ali", 40000);
    staff[1].setData("Sara", 55000);
    staff[2].setData("Usman", 30000);
    
    for(int i = 0; i < 3; i++) {
        staff[i].display();
    }
    
    Manager m("Bilal", 90000, 20000);
    PayrollOfficer officer;
    
    cout << "Pay of Ali: " << officer.calculatePay(staff[0]) << endl;
    cout << "Pay of Sara: " << officer.calculatePay(staff[1]) << endl;
    cout << "Pay of Usman: " << officer.calculatePay(staff[2]) << endl;
    cout << "Pay of Bilal (Manager): " << officer.calculatePay(m) << endl;
    
    if(isPaidMore(staff[1], staff[0])) {
        cout << "Sara is paid more than Ali\n";
    }
    
    cout << "Total employees: " << Employee::getTotalEmployees() << endl;
    
    return 0;
}