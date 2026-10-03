/*

assignment 1,
Mitchello Pierre Rene

this program keeps a record of students. User are responsible for inputing thngs like name, int and major.
For is store in a vectorList. The user interacts with a menu based do while loop to choose different options.
Like adding students, printing students, and search operations like by name and id number.

*/

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include "studentMethods.cpp"

// using namespace std;

int main()
{

    string menuInput;
    int choice;
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
                  << "to print number of students in each major enter 5: " << endl
                  << "to quit enter Q: " << endl
                  << endl
                  << "input: ";

        std::cin >> menuInput;
        std::cin.ignore();
        cout << endl;

        if (toupper(menuInput[0]) == 'Q')
        {
            Quit = true;
            cout << "exiting the program, thank you!";
            continue;
        };

        // this will catch case where letters are entered in the string
        try
        {

            choice = stoi(menuInput);
        }
        catch (const std::invalid_argument &e)
        {
            cout << "You entered character, input expecting integer" << endl;
            continue;
        };

        switch (choice)
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

            if (User_ageInput > ageUpperLimit || User_ageInput < ageLowerLimit)
            {

                cout << endl
                     << "invalid age!" << endl;
                continue;
            }
            user.setAge(User_ageInput);

            int User_idInput;
            std::cout << "Please enter student ID(6 digits) ";
            std::cin >> User_idInput;

            if (User_idInput > idUpperLimit || User_idInput < idLowerLimit)
            {

                cout << endl
                     << "invalid ID!" << endl;
                continue;
            }

            user.setID(User_idInput);

            // dont ask for major, give a choice
            char User_majorInput;
            std::cout << "Please select the student's major " << "a : Business, b: Eng, C: criminal Justice, d: medice, e: Math, f: Hum, g: others " << endl;

            cin >> User_majorInput;

            string majorResult = chooseMajor(User_majorInput);

            if (majorResult == "not found")
            {
                continue;
            }
            else
            {
                user.setMajor(majorResult);
            }

            // use student name with email extension
            string emailExtension = "@uni.edu";
            string email = user.getName();

            // checks from beginning to end of strign for white space and removes
            email.erase(remove_if(email.begin(), email.end(), ::isspace), email.end());

            user.setEmail(email + emailExtension);

            studentList.push_back(user);

            break;
        }

        case 2:
        {
            string nameSearch;
            cout << "please enter the name to search: ";
            getline(cin, nameSearch);
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

        case 5:
        {
            displayNumStudentsbyMajor();
            break;
        }
        default:
        {

            cout << "a valid menu choice was not entered" << endl;

            break;
        }
        }
    } while (!Quit);

    return 0;
}
