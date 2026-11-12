/*

    Mitchello Pierre-Rene
    11/12/26

    This program is simulating the working of a library, we are adding books with attributes like title, author, date.
    Which are stored in a vector list. We create the library.h file to perform certain task in our library, like removing a book that no longer exist,
    adding a new book, search for a collection of book by auhtor or genre. Lastly the print methods give the option to print in desc, asc, or insertion order.

*/


#include <iostream>
#include "Library.h"


using namespace std;


int main(){


    Library bhccLibrary{};

    Book b1("Game Of Thrones","GRR Martin",1996,"Fiction");
    Book b2("The Things You Carry","Tim O'Brien",1990,"War Story");
    Book b3("The Giver","Lois Lowry",1993,"Science-Fiction");
    Book b4("Outsiders","SE Hinton",1967,"Young Adult");
    Book b5("The Lord Of The Rings","John Ronald Reuel Tolkien",1955,"Fantasy");
    Book b6("House Of The Dragon","GRR Martin",2018,"Fiction");
    Book b7("If I Die in a Combat Zone: Box Me Up and Ship Me Home","Tim O'Brien",1973,"War Story");
    Book b8("Twillight","Stephenie Meyer",2005,"Young Adult");
    Book b9("The Hunger Games","Suzanne Collins",2008,"Young Adult");

    bhccLibrary.add_book(b1);
    bhccLibrary.add_book(b2);
    bhccLibrary.add_book(b3);
    bhccLibrary.add_book(b4);
    bhccLibrary.add_book(b5);
    bhccLibrary.add_book(b6);
    bhccLibrary.add_book(b7);
    bhccLibrary.add_book(b8);
    bhccLibrary.add_book(b9);



    bhccLibrary.printBooks();
    cout<<endl<<endl;

    cout<<"we are removing: "<<b1.getTitle()<<endl;
    bhccLibrary.remove_book(b1.getTitle());
    cout<<endl;

    cout<<"we are searching for book: "<<b3.getTitle()<<endl;
    bhccLibrary.find_book(b3.getTitle());
    cout<<endl;

    cout<<"we are searching for book by genre: "<<b4.getGenre()<<endl;
    bhccLibrary.get_books_by_genre(b4.getGenre());
    cout<<endl;

    cout<<"we are searching for book by author: "<<b2.getAuthor()<<endl;
    bhccLibrary.get_books_by_author(b2.getAuthor());
    cout<<endl;

    cout<<endl<<endl;
    bhccLibrary.printBooks();

    cout<<endl<<endl;
    cout<<"Printing the library by year in Ascending order"<<endl;
    bhccLibrary.printByYear_Asc();

    cout<<endl<<endl;
    cout<<"Printing the library by year in descending order"<<endl;
    bhccLibrary.printByYear_Dsc();



    return 0;
}
