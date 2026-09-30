#include <iostream>
#include <string>
#include "studentMethods.cpp"


using namespace std;


int main()
{

    string menuInput;
    int idUpperLimit = 999999, idLowerLimit = 100000;
    int ageUpperLimit = 65, ageLowerLimit = 18;

    bool Quit = false;

    do
    {
        std::cout << endl
                  << "to add student enter 1: " << endl
                  << "to search by full name enter 2: " << endl
                  << "to search by id enter 3: " << endl
                  << "to print all students enter 4: " << endl
                  << "to quit enter Q: " << endl
                  << endl
                  << "input: ";

        std::cin >> menuInput;
        std::cin.ignore();
        cout << endl;

        if (menuInput == "Q")
        {
            Quit = true;
            cout << "exiting the program, thank you!";
            continue;
        };

        switch (stoi(menuInput))
        {

        case 1:
        {
            Student user{};

            string User_nameInput;
            std::cout << "please enter Student full name ";

            std::getline(std::cin, User_nameInput);
            user.setName(User_nameInput);

            int User_ageInput;
            std::cout << "please enter student age(18+) ";
            std::cin >> User_ageInput;

            if(User_ageInput > ageUpperLimit || User_ageInput < ageLowerLimit){

                cout<<endl<<"invalid age!"<<endl;
                continue;
            }
            user.setAge(User_ageInput);

            int User_idInput;
            std::cout << "Please enter student ID ";
            std::cin >> User_idInput;

            if(User_idInput > idUpperLimit || User_idInput < idLowerLimit){

                cout<<endl<<"invalid ID!"<<endl;
                continue;
            }

            user.setID(User_idInput);

            // dont ask for major, give a choice
            string User_majorInput;
            std::cout << "Please enter student's major ";
            std::cin >> User_majorInput;
            user.setMajor(User_majorInput);

            // use student name with email extension
            string emailExtension = "@uni.edu";
            user.setEmail(user.getName() + emailExtension);

            studentList.push_back(user);

            break;
        }

        case 2:
        {
            string nameSearch;
            cout << "please enter the name to search: ";
            cin >> nameSearch;
            cin.ignore();
            cout << endl;

            Student searchResult = searchByFullName(studentList, nameSearch);

            headerTemplate();
            Student::printStudent(searchResult);
            std::cout << endl;

            break;
        }
        case 3:
        {

            int idSearch;
            cout << "please enter the ID to search: ";
            cin >> idSearch;
            cout << endl;

            Student searchResult = searchByID(studentList, idSearch);

            headerTemplate();
            Student::printStudent(searchResult);
            std::cout << endl;

            break;
        }
        case 4:
        {
            headerTemplate();
            displayAllStudents(studentList);
            break;
        }

        default:

            cout << "a valid menu choice was not entered"<<endl;

            break;
        }

    } while (!Quit);

    return 0;
}

