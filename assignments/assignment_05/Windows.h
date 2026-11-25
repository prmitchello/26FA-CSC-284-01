#pragma once

#include <ncurses.h>

class Windows {

    private:

        WINDOW* mainWin;
        WINDOW* mainInner;

        WINDOW* bottomWin;
        WINDOW* bottomInner;

        WINDOW* leftWin;
        WINDOW* leftInner;

        WINDOW* rightWin;
        WINDOW* rightInner;

public:

        Windows();

        void initialize();

        WINDOW* getTopicsWindow();

        WINDOW* getMainWindow();

        WINDOW* getChatWindow();

        WINDOW* getFriendsWindow();

};

