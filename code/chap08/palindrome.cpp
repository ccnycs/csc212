// implement the is balanced function, and add a test for it in main
#include <queue>
#include <stack>
#include <iostream>
#include <iomanip>

bool is_palindrome(const std::string& expression){
    //postcondition: A true return value indicates that word reads the same forwards and when reversed
}

int main(){
    std::string phrase;
    std::cout<<"Please enter phrase: ";
    std::getline(std::cin, phrase);
    std::cout<<"Is bool? "<<std::boolalpha<<is_palindrome(phrase)<<std::endl;
}