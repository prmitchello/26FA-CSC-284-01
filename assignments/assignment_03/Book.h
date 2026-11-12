#pragma once
#include <string>


using namespace std;

class Book{

    private:
    std::string title;
    std::string author;
    int year;
    std::string genre;


    public:

    Book(std::string t, std::string a , int y, std::string g){
        title = t;
        author = a;
        year = y;
        genre = g;
    }
    string getTitle(){
        return title;
    }
    string getAuthor(){
        return author;
    }
    string getGenre(){
        return genre;
    }
    int getYear(){
        return year;
    }
    void setTitle(string title){
        this->title=title;
    }
    void setAuthor(string author){
        this->author = author;
    }
    void setYear(int year){
        this->year=year;
    }
    void setGenre(string genre){
        this->genre = genre;
    }

    std::string toString ()
    {

        return "book" + title;
    }



};
