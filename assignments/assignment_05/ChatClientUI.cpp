/*
    Mitchello Pierre-Rene
    11/22/26
    CSC 284-01
    This application is a GUI created with the "curses" library, it allows users to chat and navigate to different
    topics and be able to view that specific tabs history and be able to add to that conversation. I use a classes and object to simplify the code and
    be better able to disect and tell what every part of the code is doing
*/

#include <iostream>
#include <string>
#include <ncurses.h>

//OOP design importing all the window components from outside classes
#include "Windows.h"
#include "RoomList.h"
#include "MessageArea.h"
#include "FriendsWindow.h"


using namespace std;


int main(){

    //initialize the screen
    initscr();

    //create the window object and initialize them with the correct window their responsible for
    Windows ui;
    ui.initialize();

    RoomList topics;
    topics.drawLeft(ui.getTopicsWindow());

    FriendsWindow friends;
    friends.drawWindow(ui.getFriendsWindow());

    //The list of chat that the user can navigate to
    //each chat stores unique conversation chain
    MessageArea generalChat;
    MessageArea sportChat;
    MessageArea musicChat;
    MessageArea randomChat;
    MessageArea programmingChat;

    //when UP or DOWN arraw keys are hit the pointer reference the correct chat
    //we set the general chat as default but that changes as the user see fit
    MessageArea* activeChat=&generalChat;


    string input="";


    //allow keyboard input in the bottom window
    keypad(ui.getChatWindow(),true);

    while (true){

        //we then read the keyboard inputs to do operation with
        int typingInput = wgetch(ui.getChatWindow());


        //depending on certain input we have to do specific tasks, --example enter should send the message
        switch(typingInput){



            case KEY_UP:{

                //change the highlight amount base on the current cursor position
                topics.selectUp();

                //the highlight amout correlates to specific chats, and the switch case handles the movement of chat
                switch(topics.getHighlight()){
                    case 0:{
                        activeChat = &generalChat;
                        break;
                    }
                    case 1:{
                        activeChat = &sportChat;
                        break;
                    }
                    case 2:{
                        activeChat = &programmingChat;
                        break;
                    }
                    case 3:{
                        activeChat = &musicChat;
                        break;
                    }
                    case 4:{
                        activeChat = &randomChat;
                        break;
                    }
                }

                //draw and update the room that was selected
                topics.drawLeft(ui.getTopicsWindow());
                //point to the referenced chat
                activeChat->drawChat(ui.getMainWindow());

                break;
            }
            case KEY_DOWN:{

                //change the highlight amount base on the current cursor position
                topics.selectDown();

                //the highlight amout correlates to specific chats, and the switch case handles the movement of chat
                switch(topics.getHighlight()){
                    case 0:{
                        activeChat = &generalChat;
                        break;
                    }
                    case 1:{
                        activeChat = &sportChat;
                        break;
                    }
                    case 2:{
                        activeChat = &programmingChat;
                        break;
                    }
                    case 3:{
                        activeChat = &musicChat;
                        break;
                    }
                    case 4:{
                        activeChat = &randomChat;
                        break;
                    }
                }

                //draw and update the room that was selected
                topics.drawLeft(ui.getTopicsWindow());
                //point to the referenced chat
                activeChat->drawChat(ui.getMainWindow());


                break;
            }

            case KEY_ENTER:
            case '\n':{

                //hitting ENTER only prints is the string is not empty
                if(!input.empty()){

                    activeChat->textInput("You: "+input);

                    activeChat->drawChat(ui.getMainWindow());

                }

                //once entered the clear the current string-building cursor, not the chat history vector
                input.clear();

                //delete enter line and mvoe the cursor to the beginning position, waitting for another typed message
                wclrtoeol(ui.getChatWindow());

                mvwprintw(ui.getChatWindow(),1,1,"Type > %s");

                wrefresh(ui.getChatWindow());


                break;
            }
            case KEY_BACKSPACE: //multiple cases to do the same things depending on what the laptop model registers
            case 127:
            case '\b': {

                //removes the last element in the vector unless already empty
                if(!input.empty()){
                    input.pop_back();
                }

                //wclrtoeol = window clear to end of line, literally delete everything in that line and redraw the string again minus the last element
                wclrtoeol(ui.getChatWindow());
                wmove(ui.getChatWindow(),1,2);

                //re-print the string and refresh the window to have it displayed
                mvwprintw(ui.getChatWindow(),1,1,"type > %s", input.c_str());
                wrefresh(ui.getChatWindow());

                break;
            }

        }

        if(typingInput >=32 && typingInput <= 126){

            //cast everything to char to stop display arrow up and down input
            input+=static_cast<char>(typingInput);

            wrefresh(ui.getChatWindow());

            wclrtoeol(ui.getChatWindow());

            wmove(ui.getChatWindow(),1,1);

            mvwprintw(ui.getChatWindow(),1,1,"Type > %s",input.c_str());

            wrefresh(ui.getChatWindow());


        }
    }

    endwin();

    return 0;

}
