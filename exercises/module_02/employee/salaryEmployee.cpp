#include <iostream>
#include "Employee.h"
using namespace std;

class salaryEmployee : private Employee
{

private:
    double salary;

public:
    salaryEmployee(string name) : Employee(name)
    {
    }

    void setSalary(double employeeSalary)
    {

        salary = employeeSalary;
    }
    double getSalary()
    {

        return salary;
    }

    void calculatePay(salaryEmployee OBJ)
    {
        cout << "Salaried Employee: " << OBJ.name << "\n";
        cout << "Monthly Salary: $" << OBJ.salary << "\n\n";
    }
};
