#include <iostream>
#include <string>

namespace MyCode
{
    void sayHello(std::string name)
    {
        std::cout << "Hello " << name << std::endl;
    }
}

int main()
{
    MyCode::sayHello("Universe");
}
