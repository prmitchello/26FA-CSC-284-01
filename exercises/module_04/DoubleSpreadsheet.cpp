#include "SpreadSheetCell.h"
#include <optional>
#include <string>
#include <string_view>

using namespace std;



class DoubleSpreadsheet : public SpreadSheetCell
{
    private:

    optional<double> data;

    public:
    //  DoubleSpreadsheet( ){
    //     data = 0;
    // }

    // DoubleSpreadsheet(string_view value){

    //     data = stringToDouble(value);
    // }

    void set(std::string_view value) override{
        data = stringToDouble(value);
    }

    std::string getString() const override{

        return doubleToString(data.value_or(0.0));
    }
    string doubleToString(double value)const
    {

       return to_string(value);
    }
    double stringToDouble(std::string_view value) const
    {
        return stod(string(value));
    }

};
