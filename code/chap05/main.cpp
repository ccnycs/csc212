#include <iostream>
#include "node1.h"

using namespace main_savitch_5;
int main(){

    node* tail = new node(1.0);
    node* second = new node(2.0, tail);
    node* first = new node(3.0, second);

    std::cout<<"length: "<<list_length(first)<<std::endl;
    
    list_head_insert(first, 13.9);
    std::cout<<"length: "<<list_length(first)<<std::endl;
    std::cout<<"head: "<<first->data()<<std::endl;
    std::cout<<"second: "<<(first->link())->data()<<std::endl;

    return 0;
}
