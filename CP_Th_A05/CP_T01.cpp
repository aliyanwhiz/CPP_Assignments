#include <iostream>
#include <string>
using namespace std;

//-- Employee structure
struct Employee
{
    string fullName;
    string department;
    float AnnualSalary;
    int yearsOfEmployment;
    int age;
};

//-- Functions Prototype
Employee GetEmployeeData();
void print_employee_info(Employee* emp);
void compute_increment(Employee* emp);
float getIncrementAmout(float AnnSalary, int age, int exp);

//-- Driver Code
int main()
{
    Employee worker = GetEmployeeData();
    print_employee_info(&worker);
    compute_increment(&worker);
    print_employee_info(&worker);

    return 0;
}

//-- Functions Definition
Employee GetEmployeeData()
{
    Employee Temp;
    cout << "Full Name : "; getline(cin, Temp.fullName);
    cout << "age : "; cin >> Temp.age;
    cout << "Department : "; cin >> Temp.department;
    cout << "Annual Salary : "; cin >> Temp.AnnualSalary;
    cout << "Years Of Employment : "; cin >> Temp.yearsOfEmployment;

    return Temp;
}

void print_employee_info(Employee* emp)
{
    cout << endl;
    cout << "[" << emp->fullName << " from "  << emp->department << " makes "  << (emp->AnnualSalary / 12) <<  " PKR a month ]," << endl;
    cout << endl;
}

void compute_increment(Employee* emp)
{
    emp->AnnualSalary += getIncrementAmout(emp->AnnualSalary, emp->age, emp->yearsOfEmployment);
    cout << "Salaries updated…" << endl;
}

float getIncrementAmout(float annSalary, int age, int exp)
{
    float res = 0.0;

    if (exp > 3 && age > 30)
        res = annSalary * 0.15;
    else if ((exp < 3 || exp > 0) && age > 30)
        res = annSalary * 0.14;
    else if ((exp < 5 || exp > 2) && (age < 30 || age > 20))
        res += annSalary * 0.12;
    else if ((exp < 2 || exp > 0) && (age < 30 || age > 20))
        res += annSalary * 0.10;

    return res;
}