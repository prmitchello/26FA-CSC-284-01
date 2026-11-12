#include <iostream>
#include <vector>
#include <list>


using namespace std;

int main(){


    vector<int> myVec = {23,45,89,54,10,64};


    cout<<"printing vector"<<endl;
    for(vector<int>::iterator it = myVec.begin(); it !=myVec.end(); ++it){
        cout<<"data :"<<*it<<endl;
    }

    cout<<endl;
    cout<<"printing vector in reverse order";
    cout<<endl;
    for(vector<int>::iterator it = myVec.end(); it != myVec.begin(); --it){
        cout<<"data :"<<*it<<endl;
    }


    list<string> myList = {"Apple","Bannana","Cherry", "date","\eos"};


    cout<<endl;
    cout<<"Printing my list items"<<endl;

        for(list<string>::iterator it=myList.begin(); it != myList.end();++it){
            cout<<"data :"<<*it<<endl;
        }

        //myList.back_inserter("Elderberry");

    return 0;
}
