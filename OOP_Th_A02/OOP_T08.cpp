#include <iostream>
using namespace std;

class Employee {
protected:
    int empId;
    string name;
public:
    Employee(int id, string n) {
        empId = id;
        name = n;
    }
    friend class EmpProfPrinter;
};

class Manager : public Employee {
    string dept;
public:
    Manager(int id, string n, string d) : Employee(id, n) {
        dept = d;
    }
    friend class EmpProfPrinter;
};

class EmpProfPrinter {
public:
    void printProfile(const Manager& m) {
        cout << "Emp ID: " << m.empId << " | Name: " << m.name << " | Department: " << m.dept << endl;
    }
};

int main() {
    Manager m(205, "Aliyan Ahmed", "IT");
    EmpProfPrinter printer;
    printer.printProfile(m);
    return 0;
}