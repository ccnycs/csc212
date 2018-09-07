#include <iostream>
#include "bag.h"

int main(){
    bag one;
    std::cout<<"Bag size: "<<one.size()<<std::endl;
    one.insert(10);
    one.insert(15);
    std::cout<<"Bag size: "<<one.size()<<std::endl;
    return EXIT_SUCCESS;
}