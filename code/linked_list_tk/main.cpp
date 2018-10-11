#include <iostream>
#include <cstdlib>
#include "node.h"

int main(){
    node *head_ptr;
    head_ptr = NULL;
    node *p, *q, *r, *s;
    p = new node;
    q = new node(4.9);
    r = new node(1.6, p);
    s = new node(13.7, q);
    std::cout<<"address: "<<&p<<std::endl;
    std::cout<<"data: "<<(*p).data()<<std::endl;
    //member selection operator: (*p).data() is the same as p->data()
    std::cout<<"data: "<< p->data()<<std::endl;
    std::cout<<"link: "<< p->link()<<std::endl;
    head_ptr = s;

    std::cout<<"size: "<<list_length(head_ptr)<<std::endl;

    list_head_insert(head_ptr, 67.9);
    std::cout<<"entry: "<<head_ptr->data()<<std::endl;
    std::cout<<"s: "<<s<<" head link: "<<head_ptr->link()<<std::endl;
    int a = 5;
    node *j;
    j = new node(a);
    int *b;
    b = &a;
    *b = 6;
    std::cout<<"j: "<<j->data()<<std::endl;
    std::cout<<"a: "<<a<<std::endl;
}
