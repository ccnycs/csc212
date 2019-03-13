#include <iostream>
#include <stack>
#include <string>

std::string reverse(const std::string& input){
    std::string output;
    std::stack <char> store;

    return output;
}

int main(){
    std::string mystr("Hello");
    std::string expected("olleH");

    std::string actual = reverse(mystr);

    if (expected==actual){
        std::cout<<"It works!";
    }else{
        std::cout<<"Expected: "<<expected<<" Actual: "<<actual<<std::endl;
    }
    return 0;
}