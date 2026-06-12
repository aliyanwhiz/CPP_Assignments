#include <iostream>
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
void print_employee_info(Employee* emp, int n);
float total_increment(Employee* emp, int n);
float getIncrementAmout(float AnnSalary, int age, int exp);

//-- Driver Code
int main()
{
    // created an array of emp for utility
    Employee workers[5] = {
        {"Aliyan Ahmed", "Software Development", 85000.0, 1, 21},
        {"Ayesha Khan", "Human Resources", 72000.0, 1, 31},
        {"Bilal Ahmed", "Sales", 68000.0, 2, 24},
        {"Sana Mirza", "Finance", 79000.0, 3, 35},
        {"Fahad Siddiqui", "Customer Support", 63000.0, 4, 28}
    };
    
    //size of workers array
    int workersLen = sizeof(workers) / sizeof(workers[0]);

    print_employee_info(workers, workersLen);
    cout << "Total increment amount is : " << total_increment(workers, workersLen) << " PKR" << endl;

    return 0;
}

//-- Functions Definition
void print_employee_info(Employee* emp, int n)
{
    cout << endl;
    int i = 0;
    cout << "[Full Name, \t\tSalary before increment, \tSalary after increment]" << endl << endl;
    while(i < n)
    {
        cout << "[" << emp[i].fullName << ", \t\t\t"  << (emp[i].AnnualSalary / 12) << ", \t\t\t\t"  << ((emp[i].AnnualSalary += getIncrementAmout(emp[i].AnnualSalary, emp[i].age, emp[i].yearsOfEmployment)) / 12) <<  "]" << endl;
        i++;
    }
    cout << endl;
}

float total_increment(Employee* emp, int n)
{
    int total= 0.0;
    int i = 0;
    while(i < n)
    {
        total += getIncrementAmout(emp[i].AnnualSalary, emp[i].age, emp[i].yearsOfEmployment);
        i++;
    }
    return total;
}

float getIncrementAmout(float annSalary, int age, int exp)
{
    float res = 0.0;

    if (exp >= 3 && age >= 30)
        res = annSalary * 0.15;
    else if (exp <= 3 && age >= 30)
        res = annSalary * 0.14;
    else if ((exp <= 5 || exp >= 2) && (age <= 30 || age >= 20))
        res += annSalary * 0.12;
    else if (exp <= 2 && (age <= 30 || age >= 20))
        res += annSalary * 0.10;

    return res;
}