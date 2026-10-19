#include <iostream>
#include <optional>
#include "SpreadSheetCell.cpp"


using namespace std;

class StringSpreadsheet : public SpreadSheetCell
{
    private:
    optional<string> data;

    public:
    void set( string_view value) override{
        data = value;
    }
    string getString() const override{
        return data.value();
    }

};
