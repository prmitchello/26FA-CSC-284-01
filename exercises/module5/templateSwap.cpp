#include <iostream>

using namespace std;

template <typename t>
void swap(t a, t b);

template <typename t1>
void Greater(t1 a , t1 b );


int main(){


    swap(3 , 6);

    Greater(23, 89);


    return 0;
}

template <typename t>
void swap (t a , t b){

    cout<<" the first number is  "<< a <<" and the second number is  "<<b<<endl;


    t temp = a;

    a = b;

    b = temp;

     cout<<" now the first number is  "<< a <<" and the second number is  "<<b<<endl;


}
template <typename t1>
void Greater(t1 a , t1 b){

    cout<<"the greater value is "<<( (a>b)? a:b );
}
