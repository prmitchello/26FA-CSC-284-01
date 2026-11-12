#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <ranges>
#include <algorithm>
#include "Book.h"


using namespace std;

class Library {

    public:

    std::vector<Book> bookCollections{};


    //: Adds a new book to the library.
    void add_book(const Book& book){

        bookCollections.push_back(book);
    }
    //Removes a book from the library based on its title.
    void remove_book(const std::string& title){


        auto result = remove_if(bookCollections.begin(),bookCollections.end(),[&title](Book& bookVar){
            return bookVar.getTitle()==title;
        });



        if(result != bookCollections.end()){

            cout<<"'"<< title <<"' was removed"<<endl;

            bookCollections.erase(result , bookCollections.end());
        }else{
            cout<< "no match to remove"<<endl;
        }


    }
    //: Searches for a book by title and returns it (if found) or prints an error message.
    void find_book(const std::string& title){

        //finds the match and use the result variable to hold it
        auto result = find_if(bookCollections.begin(),bookCollections.end(),[&title](Book& bookVar){

            return bookVar.getTitle() == title;
            }
        );

        //if result doesn't the end of the collection or null, we have a match
        if(result != bookCollections.end()){
            cout<<"Resulting book Title: '"<<result->getTitle()<<"', by author: "<<result->getAuthor()<<endl;
        }else{
            cout<< "not found"<<endl;
        }


    }
    //: Returns a collection of books written by the specified author.
    void get_books_by_author(const std::string& author){

        //this filter the vector to only hold values by said author
        auto byAuthor = bookCollections
        |std::views::filter([&author](Book& book){
            return book.getAuthor() == author;
        });

        bool found = false;

        std::ranges::for_each(byAuthor,[&found](Book& result){
            found = true;
            cout<<"Resulting book Title: "<<setw(60)<<result.getTitle()<<"by author: "<<result.getAuthor()<<endl;
        });

        //if not 1 book is found then we print not found to console
        if(!found){
            cout<< "not found";
        }


    }
    //: Returns a collection of books belonging to the specified genre.
    void get_books_by_genre(const std::string& genre){


        auto byGenre = bookCollections
        |std::views::filter([&genre](Book& book){
            return book.getGenre() == genre;
        });

        bool found = false;

        //for_each is used because there could be more then 1 book that matched the genre
        std::ranges::for_each(byGenre,[&found](Book& result){
            found = true;
            cout<<left<<"Resulting book Title: "<<setw(20)<<result.getTitle()<<" by author: "<<result.getAuthor()<<endl;
        });

        if(!found){
            cout<< "not found";
        }
    }
    //use iterator to print list of books
    void printBooks(){

        cout<<"The books currently in the library: \n"<<endl;


        cout<<left<<setw(60)<<"Title"<<setw(30)<<"Author"
            <<setw(10)<<"Year"<<setw(10)<<"Genre"<<endl;
        cout<<"------------------------------------------------------------------------------------------------------------------"<<endl;

        for(vector<Book>::iterator it = bookCollections.begin(); it<bookCollections.end(); ++it){

            cout<<left<<setw(60)<<it->getTitle()<<setw(30)<<it->getAuthor()
            <<setw(10)<<it->getYear()<<setw(10)<<it->getGenre()<<endl;

        }
    }

    void printByYear_Asc(){
        std::sort(bookCollections.begin(),bookCollections.end(),[](Book& a , Book& b){
            //comparing 2 objects by the value of the year variable
            return a.getYear() < b.getYear();
        });

        printBooks();
    }

    void printByYear_Dsc(){
        std::sort(bookCollections.begin(),bookCollections.end(),[](Book& a , Book& b){
            return a.getYear() > b.getYear();
        });

        printBooks();
    }

};

