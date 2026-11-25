#include <iostream>
#include "RoomList.h"

#include <vector>
#include <string>


using namespace std;

    //vector lsit of the topics has availlable to scroll to
    RoomList::RoomList(){
        topicList ={"General", "Sports","Programming","Music","Random"};
        highlight = 0;
    }

    void RoomList::selectUp(){

                    //if highlight is the top-most topic hitting UP again will send you back to the last, else UP goes up by one
        highlight = (highlight == 0)? topicList.size() -1: highlight-1;
    }

    void RoomList::selectDown(){

                    //if highlight is the lower-most topic pressing DOWN again will send you back to the top, else DOWN goes down by one
        highlight = (highlight == topicList.size()-1)? 0: highlight+1;

    }

    int RoomList::getHighlight(){
        return highlight;
    }

    void RoomList::drawLeft(WINDOW* leftInner){

        werase(leftInner);
        box(leftInner,0,0);


        int length = topicList.size();

        for(int i=0; i<length ; ++i){

            if(i == highlight){

                //reverse the color of the selcted topic
                wattron(leftInner, A_REVERSE);
                    mvwprintw(leftInner, (i+3) ,1,"> %s",topicList[i].c_str());
                wattroff(leftInner, A_REVERSE);

            }else{
                //every other topic is printed in their standard format
                mvwprintw(leftInner, (i+3) ,1,topicList[i].c_str());
            }

        }

        wrefresh(leftInner);

    }
