#include "SpreadSheetCell.h"
#include <optional>
#include <string>
#include <format>
#include <string_view>

using namespace std;


class DoubleSpreadsheet : public SpreadSheetCell
{
    private:

    optional<double> data;

    public:


    void set(double value){

        data = value;
    }

    void set(std::string_view value) override{
        data = stringToDouble(value);
    }

    std::string getString() const override{

        return doubleToString(data.value_or(0.0));
    }
    string doubleToString(double value)const
    {

       return format("{:.2f}",value);
    }
    double stringToDouble(string_view value) const
    {

        return stod(string( value) );
    }

};
