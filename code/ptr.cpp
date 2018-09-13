#include <iostream>

int main(){
    int i = 42;
    int *example_ptr;
    example_ptr = &i;
    std::cout<<"i :"<<i<<std::endl;
    std::cout<<"example_ptr"<<(*example_ptr)<<std::endl;
    std::cout<<example_ptr<<std::endl;
    return 0;
}