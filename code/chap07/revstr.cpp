#include <iostream>
#include <stack>
#include <string>
#include <iterator>

std::string reverse(const std::string& input){
    std::string output("");
    std::stack <char> store;
    std::string::iterator it;

    for (uint i = 0; i<input.size(); i++){
        store.push(input[i]);
    }

    while(!store.empty()){
        output+=store.top();
        store.pop();
    }
    return output;
}

int main(){
    std::string mystr("Hello");
    std::string expected("olleH");

    std::string actual = reverse(mystr);

    if (expected==actual){
        std::cout<<"It works!"<<std::endl;
    }else{
        std::cout<<"Expected: "<<expected<<" Actual: "<<actual<<std::endl;
    }
    return 0;
}