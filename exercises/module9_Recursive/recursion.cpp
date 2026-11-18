#include <iostream>

int recursive(int );
void print(int );
void fibonacci(int , int , int );

int main(){

    //int argc, char* argv[]
    // if(argc<2){
    //     std::cout<<"usage: factorial number";
    // }

    int paramNumber=4;

    int factorial_Result  = recursive(paramNumber);

    std::cout<<"The factorial sum of: "<<paramNumber<<"! is "<<factorial_Result<<std::endl;

    //int Fibinacci_Result  = fibonacci(paramNumber,0,0);

    std::cout<<"The fibonacci sum of: "<<paramNumber<<" is ";
    fibonacci(paramNumber,0,0);

    return 0;
}

int recursive(int num){


    if(num == 0) return 1;

    //int sum =;
    //std::cout<<num;

    return recursive(num-1) * num;
}
void fibonacci(int numTimes, int n1, int n2){

    numTimes = numTimes -1;

    if(numTimes == 0) return ;

    n2 = n2 + 1;

    //n2 = fibonacci(numTimes,n1,n2+1);

    int sum = n1 + n2;


  fibonacci(numTimes, n1, n2);
   std::cout<<"this is num2 "<<n2<<std::endl;
   std::cout<<"this is Total sum "<<sum<<std::endl;
}
void print(int num){
    for(int i=0; i < num ; i++){
        std::cout<<i<<std::endl;
    }
}