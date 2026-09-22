
#include <iostream>
using namespace std;
class Animal{

public:


void speak(){
    cout<<"sound";
}






};
class Dog : Animal {


public:

void speak(){

    cout<<"woof";
}


};

int main(){


    Dog p;

    Animal A;

    A.speak();
    p.speak();

    Animal a = new Dog();

a.speak();


    return 0;
}
