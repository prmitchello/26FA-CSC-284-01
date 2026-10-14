#include <iostream>
#include "SpreadSheetCell.cpp"

using namespace std;


int main(){
    int d = 8;


    SpreadSheetCell c1("this is now a string");
    SpreadSheetCell c2(123.2);
    SpreadSheetCell c3(-123.2);
    SpreadSheetCell c4(123);


    cout<<c1.getValue()<<endl;
    cout<<c2.getValue()<<endl;
    cout<<c3.getValue()<<endl;
    cout<<c4.getValue()<<endl;

    return 0;
}
