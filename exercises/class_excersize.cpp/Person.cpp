#include <iostream>
#include <String>

using namespace std;

class Person{
    private:


    string firstName;
    string lastName;


    public:
    Person(string firstName, string lastName){
        this->firstName = firstName;
        this->lastName = lastName;
    }


    string getFirstName()const{
        return firstName;
    }
    string getLastName()const{
        return lastName;
    }
    void setFirstName(string firstName){
        this->firstName = firstName;

    }
    void setLastName(string lastName){
        this->lastName = lastName;
    }

};
