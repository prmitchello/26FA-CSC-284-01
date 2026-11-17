/*
    Mitchello J. Pierre-Rene
    11/16/26
    CSC 284-01

    This program is using multithreading to read a series of files and find matches to a list of keywords
    the program expect 2 argumnets during compile time to identify the folder directory

*/


#include "LogAnalyzer.h"
#include <iostream>
#include <filesystem>
#include <thread>
#include <vector>

using namespace std;
namespace fs = filesystem;

int main(int argc, char* argv[]) {

    //the progam is expecting 2 arguments passed, any less will encounter this error
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <log_directory>\n";
        return 1;
    }

    //the second argument is pass to a string variable
    string folderPath = argv[1];

    LogAnalyzer analyzer;

        //list of key words that need to be searched for
        vector<string> keywords = {"[ERROR]", "[WARN]", "[INFO]", "[FATAL]", "[DEBUG]", "[TRACE]"};

        //declaration of thread array list
        vector<thread> threads;

    cout << "Analyzing folder: " << folderPath << "\n\n";


    int fileCount=0;

    //using a for loop to iterate through all files in the directory path
    for(auto& data : fs::directory_iterator(folderPath)){

        fileCount++;

        //these file system method function are used here to ensure we have a right match for the .log file
        if(data.is_regular_file() && data.path().extension()==".log"){

            string filename = data.path().string();

            //the vector method embrace_back() create a new thread element in the vector
            //we pass in the address to the class method, the object analyzer, file, and the list of keywords
            threads.emplace_back(&LogAnalyzer::analyzeFile,&analyzer,filename, keywords);

        }else{
            cout<<"sending directory not file";
        }

    }


    //Join all threads after launching.
    for( thread& t : threads){

        //iterates through vector list of threads and join them all
        t.join();

    }

    //after the processing threads in joined the main function thread is free to resume
    //print the final count for each key word
    analyzer.printSummary();

    cout<<"Analysis complete. Processed "<< fileCount <<" files. \n"<<endl;

    return 0;
}
