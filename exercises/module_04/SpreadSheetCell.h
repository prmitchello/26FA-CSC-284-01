
    #pragma once

    #include <iostream>
    #include <string>
    #include <string_view>

    using namespace std;

    class SpreadSheetCell {

        public:
        virtual ~SpreadSheetCell() = default;
        virtual void set( string_view value )=0;
        virtual string getString() const =0;

    };
