#include <iostream>
#include <string>
#include "Student.cpp"
#include <vector>

using namespace std;

vector<Student> studentList{};

void displayAllStudents(vector<Student> &studentList)
{
    if (studentList.size() == 0)
    {
        cout << "There are currently no students to print" << endl;
    }
    else
    {

        for (int i = 0; i < studentList.size(); i++)
            Student::printStudent(studentList[i]);
    }
}
Student searchByFullName(vector<Student> &studentList, string fullName)
{

    Student noStudentFlag{-1, "N/A", -1, "N/A", "N/A"};
    for (int i = 0; i < studentList.size(); i++)
    {


        if (studentList[i].getName() == fullName)
        {
            return studentList[i];
        }
    }
    std::cout << endl
              << "Student not found in the registery \n"
              << endl;

    return noStudentFlag;
}
Student searchByID(vector<Student> &studentList, int IDSearch)
{

    Student noStudentFlag{-1, "N/A", -1, "N/A", "N/A"};
    for (int i = 0; i < studentList.size(); i++)
    {

        if (studentList[i].getID() == IDSearch)
        {
            return studentList[i];
        }
    }

    std::cout << endl
              << "Student not found in the registery \n"
              << endl;

    return noStudentFlag;
}
void headerTemplate()
{
    std::cout << "ID " << std::setw(10) << "Name" << std::setw(20) << "Age" << std::setw(10) << "Major" << std::setw(20) << "Email" << std::endl;
    std::cout << " ---------------------------------------------------------------------" << std::endl;
}
