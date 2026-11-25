#include "Windows.h"


    //default constructor to set to null
    Windows::Windows(){

        mainWin=nullptr;
        mainInner=nullptr;

        bottomWin=nullptr;
        bottomInner=nullptr;

        leftWin=nullptr;
        leftInner=nullptr;

        rightWin=nullptr;
        rightInner=nullptr;

    }


    void Windows::initialize(){

        //COLS/LINES is defined in the curses library and returns the size of the computer screen its running in
        int terminalWidth=COLS;
        int terminalLength=LINES;

        //some hard coded values to have the windows and boxes nicely alligned
        int sidePanelWidth =20;
        int sidePanelLength = terminalLength -1;

        int y_startAt_0 = 0;
        int x_startAt_0 = 0;

        //the actual step of create the Windows, they have a shell and an Inner to host contents
        mainWin = newwin((sidePanelLength -10) ,(terminalWidth-40),y_startAt_0,(x_startAt_0 + 20));
        mainInner = newwin((sidePanelLength -13) ,(terminalWidth-42),y_startAt_0+2,(x_startAt_0 + 21));

        bottomWin = newwin( 10 ,(terminalWidth-40),(terminalLength - 11) , (x_startAt_0 + 20) );
        bottomInner = newwin( 5 ,(terminalWidth-44),(terminalLength - 8) , (x_startAt_0 + 22) );

        rightWin = newwin(sidePanelLength,sidePanelWidth,y_startAt_0,(terminalWidth-20));
        rightInner = newwin(sidePanelLength-3,sidePanelWidth-4,y_startAt_0+2,(terminalWidth-18));

        leftWin = newwin(sidePanelLength,sidePanelWidth,y_startAt_0,x_startAt_0);
        leftInner = newwin(sidePanelLength-3,sidePanelWidth-4,y_startAt_0+2,x_startAt_0+2);

        mvwprintw(rightWin,1,6,"Friends");
        mvwprintw(leftWin,1,8,"Feed");
        mvwprintw(bottomInner,1,1,"Type > ");
        mvwprintw(mainWin,1,40,"Advanced C++ Chat Client");

        // box creates a border for each win and gives them a visible effect
        box(mainWin,0,0);
        box(mainInner,0,0);
        box(bottomWin,0,0);
        box(bottomInner,0,0);
        box(leftWin,0,0);
        box(leftInner,0,0);
        box(rightWin,0,0);
        box(rightInner,0,0);

        //refresh to have all Windows appear on screen
        wrefresh(mainWin);
        wrefresh(mainInner);
        wrefresh(bottomWin);
        wrefresh(bottomInner);
        wrefresh(rightWin);
        wrefresh(rightInner);
        wrefresh(leftWin);
        wrefresh(leftInner);

    }

    //getters to acces in the main
    WINDOW* Windows::getTopicsWindow(){
        return leftInner;
    }
    WINDOW* Windows::getMainWindow(){
        return mainInner;
    }
    WINDOW* Windows::getChatWindow(){
        return bottomInner;
    }
    WINDOW* Windows::getFriendsWindow(){
        return rightInner;
    }
