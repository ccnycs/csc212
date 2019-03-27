#include <iostream>
#include <stack>

void printNumR(uint n){
    if (n==0){return;}
    printNumR(n/10);
    std::cout<<n%10<<std::endl;
    return;
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
    printNumR(n);
    return 0;
}