#include <iostream>
using namespace std;

class Person{
public:
    void eat()
    {

        cout << "Person is eating" << endl;
    }
};

class Employee : public Person{
public:
    void work()
    {

        cout << "Employee is working" << endl;
    }
};

class Manager : public Employee{
public:
    void manage()
    {

        cout << "Manager is managing" << endl;
    }
};

int main(){

    Manager m;
    m.eat();
    m.work();
    m.manage();

    return 0;
}