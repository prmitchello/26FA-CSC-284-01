#include <iostream>
#include <vector>
#include <memory>
#include <utility>

#include "SpreadSheetCell.h"
#include "DoubleSpreadsheet.cpp"
#include "StringSpreadsheet.cpp"

using namespace std;


int main(){

    vector<unique_ptr<SpreadSheetCell>> Excel ;


    unique_ptr<SpreadSheetCell> cell = make_unique<DoubleSpreadsheet>();
    unique_ptr<SpreadSheetCell> cell1 = make_unique<StringSpreadsheet>();
    unique_ptr<SpreadSheetCell> cell2 = make_unique<DoubleSpreadsheet>();


    cell->set("34.5");
    cell1->set("hello");
    cell2->set("30");

    //ereradf

    Excel.push_back(std::move(cell));//move(cell)
     Excel.push_back(std::move(cell1));
    Excel.push_back(std::move(cell2));


    for(const unique_ptr<SpreadSheetCell> & cell : Excel){
        cout<<cell->getString()<<endl;
        cout<<cell1->getString()<<endl;
        cout<<cell2->getString()<<endl;
    }


    return 0;
}
