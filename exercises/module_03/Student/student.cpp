#include <iostream>
#include <string>

class Student
{
private:
    std::string name;

public:
    Student(const std::string &n) : name(n)
    {
        std::cout << "Student created: " << name << '\n';
    }

    ~Student()
    {
        std::cout << "Student destroyed: " << name << '\n';
    }

    void introduce() const
    {
        std::cout << "Hi, I'm " << name << '\n';
    }
};

void introduceStudent()
{
    // auto student(new Student("Alice"));

    // auto student = std::make_unique<Student>("Ali");
    std::unique_ptr<Student> student = std::make_unique<Student>("Alyson");

    student->introduce();
}

int main()
{
    introduceStudent();
}
