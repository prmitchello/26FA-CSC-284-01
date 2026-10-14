#include <string_view>


template <typename T >
class SpreadSheetCell{

    private:

    T value;


    public:

    SpreadSheetCell(T val){
        value = val;
    }

    void setValue(T val){
        value = val;

    }
    T getValue(){
        return value;
    }



};
