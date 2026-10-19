#include <iostream>
#include <vector>
#include <memory>
#include <utility>

#include "SpreadSheetCell.h"
#include "DoubleSpreadsheet.cpp"

//#include "StringSpreadsheet.cpp"

using namespace std;


int main(){

    vector<unique_ptr<SpreadSheetCell>> Excel ;


  unique_ptr<SpreadSheetCell> cell = make_unique<DoubleSpreadsheet>();


    cell->set("34.5");

    Excel.push_back(std::move(cell)); //move(cell)


    for(const unique_ptr<SpreadSheetCell> & cell : Excel){
        cout<<cell->getString();
    }


    return 0;
}
