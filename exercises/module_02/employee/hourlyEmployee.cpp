
#include <iostream>
#include "Employee.h"

using namespace std;

class hourlyEmployee : private Employee
{

private:
    double hourlyRate;
    double hoursWorked;

public:
    hourlyEmployee(string name) : Employee(name)
    {
    }

    void setRate(double employeeRate)
    {

        hourlyRate = employeeRate;
    }
    double getRate()
    {

        return hourlyRate;
    }

    void setHoursWorked(double workHours)
    {
        hoursWorked = workHours;
    }
    double getHoursWorked()
    {
        return hoursWorked;
    }

    void calculatePay(hourlyEmployee instanceOBJ)
    {

        double totalPay = instanceOBJ.hourlyRate * instanceOBJ.hoursWorked;
        cout << "Hourly Employee: " << instanceOBJ.name << "\n";
        cout << "Total Pay: $" << totalPay << "\n\n";
    }
};
