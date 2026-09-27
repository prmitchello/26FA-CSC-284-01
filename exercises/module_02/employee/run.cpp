#include <iostream>
#include "hourlyEmployee.cpp"
#include "salaryEmployee.cpp"

using namespace std;

int main()
{

    salaryEmployee employee{"Erick"};
    hourlyEmployee employee2("Paul");

    employee2.setRate(25);
    employee2.setHoursWorked(40);
    employee2.calculatePay(employee2);

    employee.setSalary(95000);
    employee.calculatePay(employee);

    return 0;
}
