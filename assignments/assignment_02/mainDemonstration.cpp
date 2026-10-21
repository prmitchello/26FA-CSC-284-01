#include <iostream>
#include <vector>
#include <memory>
#include <utility>

#include "SpreadSheetCell.h"
#include "DoubleSpreadsheet.h"
#include "StringSpreadsheet.h"

using namespace std;


int main(){

    vector<unique_ptr<SpreadSheetCell>> Excel ;


    unique_ptr<SpreadSheetCell> cell = make_unique<StringSpreadsheet>();
    unique_ptr<SpreadSheetCell> cell1 = make_unique<DoubleSpreadsheet>();
    unique_ptr<SpreadSheetCell> cell2 = make_unique<DoubleSpreadsheet>();


    cell->set("hello");
    cell1->set("18.1");
    cell2->set("12.1");

    Excel.push_back(std::move(cell));//move(cell)
     Excel.push_back(std::move(cell1));
    Excel.push_back(std::move(cell2));


    cout<<"Vector: [";

    for(const unique_ptr<SpreadSheetCell> & cell : Excel){
        cout<< cell->getString() << ", ";
    }
    cout<<"]";

    return 0;
}
