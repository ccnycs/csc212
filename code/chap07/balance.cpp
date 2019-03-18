// implement the is balanced function, and add a test for it in main
#include <stack>
#include <string>
#include <cassert>
#include <iostream>
#include <iomanip>

bool is_balanced(const std::string& expression){
    //postcondition: A true return value indicates that the parenthesis 
    //in the given expression are balanced
    //otherwise return false
    std::stack <char> input;
    for(uint i=0; i<expression.length(); i++){
        if(expression[i] == '('){
            input.push('(');
        }
        if(expression[i]==')'){
            if (input.empty()){
                return false;
            }
            input.pop();
        }
    }

    return input.empty();

}

int main(){
    assert(is_balanced(std::string("()")));
    assert(! is_balanced(std::string("(")));
    assert(! is_balanced(std::string(")(")));
    assert(is_balanced(std::string("")));
    std::string pstring;
    std::cout<<std::boolalpha;
    do{
        std::cout<<"Enter p string: ";
        std::cin>>pstring;
        std::cout<<"is balanced: "<<is_balanced(pstring)<<std::endl;
    }while(pstring!="q");
}
