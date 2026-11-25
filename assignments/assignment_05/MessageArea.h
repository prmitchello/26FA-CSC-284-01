#pragma once

#include <vector>
#include <string>
#include <ncurses.h>


using namespace std;

class MessageArea {

    private:

        vector<string> messages;

    public:

        MessageArea();

        void textInput( string input );

        void drawChat(WINDOW* mainInner);

};

