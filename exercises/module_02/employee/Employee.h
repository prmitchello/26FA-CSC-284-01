
#include <iostream>
#include <string>

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

using namespace std;

class Employee
{

protected:
    string name;

public:
    Employee(string Name)
    {
        name = Name;
    }

    string getName()
    {
        return name;
    }

    void setName(string set)
    {
        name = set;
    }
    virtual void calculatePay()
    {
    }
};
#endif
