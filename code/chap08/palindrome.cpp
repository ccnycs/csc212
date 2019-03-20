// implement the is balanced function, and add a test for it in main
#include <queue>
#include <stack>
#include <iostream>
#include <iomanip>
#include <cassert>

bool is_palindrome(std::string expression){
    /**postcondition: A true return value indicates that word reads 
    the same forwards and when reversed**/
    std::stack <char> reverse;
    std::queue <char> forward;
    char letter;
    for(uint i=0; i<expression.length(); i++){
        letter = std::tolower(expression[i]);
        reverse.push(letter);
        forward.push(letter);
    }
    assert(reverse.size()==forward.size());
    while(!forward.empty()){
        if(reverse.top()!=forward.front()){
            return false;
        }
        reverse.pop();
        forward.pop();
    }  
    return true;
}

int main(){
    std::string phrase;
    std::cout<<"Please enter phrase: ";
    std::getline(std::cin, phrase);
    std::cout<<"Is bool? "<<std::boolalpha<<is_palindrome(phrase)<<std::endl;
}