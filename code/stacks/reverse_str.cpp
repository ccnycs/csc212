#include <stack>
#include <string>
#include <iostream>

std::string reverse(std::string input){
    std::string output;
    std::stack <char> store;
   
    for (std::string::iterator it=input.begin(); it!=input.end(); ++it){
        store.push(*it);
    }
    
    while(!store.empty()){
        output+=store.top();
        store.pop();
    }

    return output;
}

int main(){
    std::cout<<reverse(std::string("Hello"));
}