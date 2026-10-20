#include <iostream>
#include <string>

template <typename T >

void printValue(T value){

    std::cout<<value <<std::endl;
}

template <>

void printValue<bool>(bool value){

    std::cout<< ( (value > 0 )? "true": "false" );
}


int main(){


    printValue(42);
    printValue(3.14);
    printValue<bool>(1);
    printValue(false);
    // printValue(42);


    return 0;
}
