#pragma once


#include <string>
//#ifndef BASE_H
//#define BASE_H
class Base {
public:
    std::string someMethod();
protected:
    int m_protectedInt { 0 };
private:
    int m_privateInt { 0 };
};
//#endif
