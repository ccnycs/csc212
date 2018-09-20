#include <iostream>
#include "node.h"

int main(){
    auto p = new node(3.0);
    std::cout<<p->data()<<std::endl;
}