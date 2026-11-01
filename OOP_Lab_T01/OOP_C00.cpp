#include <iostream>
using namespace std;

class Person{
    int natId;
    string name;
    int yob;
public:
    Person(int id, string n, int year): natId(id), name(n), yob(year) {};
    int getAge(){
        return 2026 - yob;
    };
};

class Employee: public Person{
    int empId;
    string designation;
    float salary;
public:
    Employee(int id, string n, int year, int eid, string des, float s): Person(id, n, year), empId(eid), designation(des), salary(s) {};
};

int main(){
    Employee e(83331023, "Aliyan Ahmed", 2005, 10928, "Software Engineer", 75000.0);
    cout << e.getAge() << endl;
    return 0;
}