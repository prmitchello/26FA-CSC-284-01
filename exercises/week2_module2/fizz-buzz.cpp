#include <iostream>

using namespace std;

int main()
{

    int fizz = 3, buzz = 5;

    for (int i = 1; i < 47; i++)
    {

        if (i % fizz == 0 && i % buzz == 0)
        {
            cout << "fizz_Buzz" << endl;
        }

        else if (i % fizz == 0)
        {
            cout << "Fizz" << endl;
        }
        else if (i % buzz == 0)
        {
            cout << "Buzz" << endl;
        }
        else
        {
            cout << i << endl;
        }
    }

    return 0;
}
