#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <typename lambFunctor>

auto applyOperation(auto value , lambFunctor func){

    auto resultCapture = func(value);

    return resultCapture;

}


int main(){

    auto lambdaSquare = [=](int value){
        return  value * value;
    };

    auto lambdaTimes2 = [=](int value){
        return  value * 2;
    };

    auto lambdaAdd10 = [=](int value){
        return  value +10;
    };

    auto lambdaOddEven = [=](int value){

        string s = ((value % 2 == 0 )? "even":"odd");

        return  s;
    };


    int resultSquare = applyOperation(4 , lambdaSquare );

    std::cout << "this lambda squares the value it receives " <<resultSquare <<std::endl ;



    int resultTimes2 = applyOperation(4 , lambdaTimes2 );

    std::cout<< "this lambda multiply the value it receives by 2 " << resultTimes2 << std::endl;



    int resultAdd10 = applyOperation(4 , lambdaAdd10 );

    std::cout << "this lambda adds 10 the value it receives " << resultAdd10<< std::endl ;



    auto resultOddEven = applyOperation(4 , lambdaOddEven);

    std::cout << "this lambda checks if the value it recieves is odd or even " << resultOddEven ;



    vector<int> myVec { 42, 17, 85, 23, 64, 9, 51} ;

    sort(myVec.begin(),myVec.end());

    cout<<"the sort vector is : ";
    for(auto &v : myVec){
        cout<<" "<< v ;
    }


  // int great = max_element( myVec.begin(),myVec.end() );


  cout<<endl;

  // cout << "max element is " << great;
   for(auto &v : myVec){
        cout<< v <<" ";
    }



    return 0;
}

void sort(){




}
// auto maxEement(vector<int> &myVec){

//     int greatest = myVec[0];





// }
