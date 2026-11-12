#include <iostream>
#include <ncurses.h>

int main(int argc, char ** argv){

    // init screen and sets up screen
    initscr();

    // print to screen
    printw("Hello World");

    printw("Hello World");
    printw("Hello World");

    printw("Welcome!");
    mvprintw(5, 10, "Located at row 5, col 10");


    keypad(stdscr, TRUE);  // Enable special keys
    noecho();           // Do not echo typed chars
    int ch = getch();
    switch (ch) {
        case KEY_UP: printw("Up key!"); break;
        case 'q': printw("Quit key!"); break;
    }



    // refreshes the screen
    refresh();

    // pause the screen output
    getch();

    // deallocates memory and ends ncurses
    endwin();




return 0;
}
