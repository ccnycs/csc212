#include <iostream>
#include <string>

template <class Item>
Item add2(Item a, Item b){
 
 return a+b;
}

int main(){
    std::string a("hello ");
    std::string b("world!");
    std::cout<<add2(2,3)<<std::endl;
    std::cout<<add2('h', 'i')<<std::endl;
    std::cout<<add2(a, b)<<std::endl;
}