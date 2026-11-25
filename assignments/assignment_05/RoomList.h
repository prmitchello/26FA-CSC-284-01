#pragma once

#include <vector>
#include <string>
#include <ncurses.h>


using namespace std;

class RoomList {

    private:

        vector<string> topicList;
        int highlight;

    public:

        RoomList();

        void selectUp();

        void selectDown();

        int getHighlight();

        void drawLeft(WINDOW* );

};
