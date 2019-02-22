#include <iostream>
#include "node1.h"

using namespace main_savitch_5;
int main(){
    node* tail = new node(1.0);
    node* second = new node(2.0, tail);
    node* third = new node(3.0, second);

    return 0;
}
