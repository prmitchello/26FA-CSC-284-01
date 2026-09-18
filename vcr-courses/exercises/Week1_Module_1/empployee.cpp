#include <iostream>
#include <format>
#include "employee.h"

// g++ -std=c++23 -o employee.exe employee.cpp
int main()
{
    Employee anEmployee;
    anEmployee.firstInitial = 'P';
    anEmployee.lastInitial = 'S';
    anEmployee.employeeNumber = 42;
    anEmployee.salary = 80000;

    std::cout << std::format("Employee: {}{}", anEmployee.firstInitial, anEmployee.lastInitial) << std::endl;
    std::cout << std::format("Number: {}", anEmployee.employeeNumber) << std::endl;
    std::cout << std::format("Salary: ${}", anEmployee.salary) << std::endl;
}
