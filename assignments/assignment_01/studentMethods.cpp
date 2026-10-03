#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include "Student.cpp"
#include <vector>
#include <format>

using namespace std;

static int busCount = 0, engCount = 0, crimCount = 0,
           medCount = 0, mathCount = 0, humCount = 0, othersCount = 0;

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
string chooseMajor(char charInput)
{

    string Bus = "Business", Eng = "Eng", Crim = "criminal Justice",
           Med = "Medice", Math = "Math", Hum = "Humanitites", others = "Others";

    switch (charInput)
    {

    case 'a':
    {

        busCount++;

        return Bus;

        break;
    }
    case 'b':
    {

        engCount++;

        return Eng;

        break;
    }
    case 'c':
    {

        crimCount++;
        return Crim;

        break;
    }
    case 'd':
    {

        medCount++;
        return Med;

        break;
    }
    case 'e':
    {

        mathCount++;
        return Math;

        break;
    }

    case 'f':
    {

        humCount++;
        return Hum;

        break;
    }
    case 'g':
    {

        othersCount++;
        return others;

        break;
    }
    default:
    {

        cout << "invalid character entered" << endl;
        break;
    }
    }
    string nf = "not found";
    return nf;
}

void displayNumStudentsbyMajor()
{

    cout << endl
         << format("the number of students in each major. Business: {} Math: {}  Engineering: {}  Medicine:  {}  Humanities: {} Criminal Justice: {}   Others: {} ",
                   busCount, mathCount, engCount, medCount, humCount, crimCount, othersCount)
         << endl;
}

void validateName(string &nameInput)
{

    size_t startOfString = nameInput.find_first_of(" \t");
    size_t endOfString = nameInput.find_last_not_of(" \t");

    if (startOfString != string::npos)
    {

        nameInput = nameInput.substr(startOfString - endOfString + 1);
    }
    else
    {
        nameInput = " ";
    }
}
