#include <iostream>
#include "base.h"
#include "derived.h"



using namespace std;

int main()
{
    Base base;
    cout << base.someMethod() << endl;
}
