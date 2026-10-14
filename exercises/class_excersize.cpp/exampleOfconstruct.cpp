#include <iostream>
#include <utility>
#include <vector>

class MyClass {
public:
    MyClass() { std::cout << "Default\n"; }
    MyClass(int x) { std::cout << "Parameterized\n"; }
    MyClass(const MyClass& other) { std::cout << "Copy\n"; }
    MyClass(MyClass&& other) { std::cout << "Move\n"; }
};


MyClass makeTempObject() {
    std::cout << "Creating temporary object...\n";
    return MyClass(42); // returns a temporary object
}
