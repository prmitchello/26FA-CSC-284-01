#include <iostream>
#include "LogAnalyzer.h"

#include <fstream>
#include <thread>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void LogAnalyzer::analyzeFile(const string& filename, const vector<string>& keywords) {

    ifstream file(filename);

    //pre-eliminary check if file exist and can open
    if (!file) {
        cerr << "Error: Could not open file " << filename << "\n";
        return;
    }

    //i encountered a error we the cout we malformed because of a race condition
    //the mutex makes this statement more consistent
    {
        lock_guard<mutex> lock(countMutex);
        cout << "Processing: " << filename << endl;
    }


    string wordbyword;
    

    while(file>>wordbyword){

        //for loop the check the current word we're reading in file against the list of 6 key words
        for(string key : keywords){

            //if a match is found lock the acces using lock_guard
            if(wordbyword == key){

                //1 thread access at a time
                lock_guard<mutex> lock(countMutex);

                //increment the whichever key is found
                keywordCounts[key]++;
            }
        }
    }
    file.close();
}

void LogAnalyzer::printSummary() const {
    cout << "\n--- Keyword Summary ---\n";

    lock_guard<mutex> lock(countMutex);

    //for_each and a lambda to print keyword counts.

    for_each(keywordCounts.begin(),keywordCounts.end(),[](auto &data){
        cout<<data.first << ": "<<data.second<<endl;
    } );

    cout << "-----------------------\n";
}
