#include <iostream>
#include <string>
#include <iomanip>

// using namespace std;

class Student
{

private:
    int id;
    std::string name;
    int age;
    std::string major;
    std::string email;

public:
    Student()
    {
    }
    Student(int Id, std::string Name, int Age, std::string Major, std::string Email)
    {

        id = Id;
        name = Name;
        age = Age;
        major = Major;
        email = Email;
    }

    void setID(int ID)
    {
        int upperLimit = 999999;
        int lowerLimit = 100000;

        if (ID > upperLimit || ID < lowerLimit)
        {

            std::cout << "invalid ID!" << std::endl;

            id = -1;
        }
        else
        {
            id = ID;
        }
    }
    int getID()
    {
        return id;
    }

    void setName(std::string Name)
    {
        name = Name;
    }
    std::string getName()
    {
        return name;
    }

    void setAge(int Age)
    {
        int upperLimit = 65;
        int lowerLimit = 18;
        if (Age > upperLimit || Age < lowerLimit)
        {

            std::cout << "invalid age!" << std::endl;
            age = -1;
        }
        else
        {
            age = Age;
        }
    }
    int getAge()
    {
        return age;
    }

    void setMajor(std::string Major)
    {
        major = Major;
    }
    std::string getMajor()
    {
        return major;
    }

    void setEmail(std::string Email)
    {
        email = Email;
    }
    std::string getEmail()
    {
        return email;
    }

    static void printStudent(Student studentInstance)
    {
        std::cout << studentInstance.getID() << std::setw(15) << studentInstance.getName()
                  << std::setw(20) << studentInstance.getAge() << std::setw(10) << studentInstance.getMajor() << std::setw(20)
                  << studentInstance.getEmail() << std::endl;
    }
};
