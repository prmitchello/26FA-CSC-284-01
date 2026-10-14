#include <iostream>
#include "Person.cpp"
#include "exampleOfconstruct.cpp"



int main(){


    Person student1("Bob", "Riley");

    //Person phoneBook[3];





    MyClass b(10);

    std::cout << "\n--- Copy---\n";
    MyClass c = b; // or MyClass c(b);

    std::cout << "\n--- Move(with std::move) ---\n";
    MyClass d = std::move(b);

    std::cout << "\n--- Move(from temporary) ---\n";
    MyClass e = makeTempObject();

    std::cout << "\n--- Adding to Vector ---\n";
    std::vector<MyClass> vec;
    vec.push_back(MyClass(100));



    return 0;
}
