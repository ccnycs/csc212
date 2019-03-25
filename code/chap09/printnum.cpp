#include <iostream>
#include <stack>

void printNumR(uint n){

}

void printNumI(uint n){
    std::stack <uint> numbers;
    while(n>0){
        numbers.push(n%10);
        n/=10;
    }
    while(!numbers.empty()){
        std::cout<<numbers.top()<<std::endl;
        numbers.pop();
    }
}

int main(){
    std::cout<<"enter number: ";
    uint n;
    std::cin>>n;
    printNumI(n);
    return 0;
}