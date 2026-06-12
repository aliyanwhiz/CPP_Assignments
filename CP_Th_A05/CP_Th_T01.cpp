#include <iostream>
using namespace std;

//-- Employee structure
struct Employee {
    int id;
    string fullName;
    string department;
    double AnnualSalary;
    int yearsOfEmployment;
    int age;
};

//-- Functions Prototype
void compute_increment(Employee& emp);

int main(){


    return 0;
}

//-- Functions Defination
void compute_increment(Employee& emp) {
    double increment = 0.0;

    if (emp.yearsOfEmployment > 3 && emp.age > 30)
        increment += emp.AnnualSalary * 0.15; // Scenario 4
    else if ((emp.yearsOfEmployment < 3 || emp.yearsOfEmployment > 0) && emp.age > 30)
        increment += emp.AnnualSalary * 0.14; // Scenario 3
    else if ((emp.yearsOfEmployment < 5 || emp.yearsOfEmployment > 3) && (emp.age < 30 || emp.age > 20))
        increment += emp.AnnualSalary * 0.12; // Scenario 2
    else if ((emp.yearsOfEmployment < 2 || emp.yearsOfEmployment > 0) && (emp.age < 30 || emp.age > 20))
        increment += emp.AnnualSalary * 0.10; // Scenario 1
        
    emp.AnnualSalary += increment; // Update the annual salary with the increment
}