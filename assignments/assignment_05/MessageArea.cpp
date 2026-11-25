#include <iostream>
#include "MessageArea.h"

#include <vector>
#include <string>


using namespace std;

//default construtcor not doing much actually
MessageArea::MessageArea(){

}

//add a whole text string to the vector, same vector which is used to display chat history
void MessageArea::textInput( string input ){

    messages.push_back(input);
}

void MessageArea::drawChat(WINDOW* mainInner){

    werase(mainInner);

    box(mainInner,0,0);

    //total number of message availlable
    int numMessages = messages.size();

    //width is not used here, but if the message was overflowing onto other windows
    //the chatWidth value could be used to handle it
    int chatHeight,chatWidth;

    //getmaxyx is another "curses" library defined function, returns the max lenght/widht of the window passed as argument
    getmaxyx(mainInner,chatHeight,chatWidth);

        //the function max use a floor of zero, and ruturns where we shoudl start inside the
        //vector pending on screen size
        int displayStart= max(0, static_cast<int>(messages.size()) - (chatHeight-1));

    int rowTotal=1;

    //print the chat history starting at appropriate index and the chat grows
    for(int i=displayStart; i< numMessages; i++){

        mvwprintw( mainInner, rowTotal++, 1, messages[i].c_str());

    }

    wrefresh(mainInner);
}


