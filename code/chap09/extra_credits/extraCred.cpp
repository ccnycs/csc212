#include <iostream>

static int counter = 1;

void print_recursion(int n){
    if(counter > n)
        return;
    std::string tabs = "";
    for(int i = 0; i < counter; i++)
        tabs += "\t";
    std::cout << tabs << "This was written by call number " << counter << "." << std::endl;
    counter ++;
    print_recursion(n);
    counter --;
    std::cout << tabs << "This ALSO written by call number " << counter << "." << std::endl;
    return;
}

int main(){
    print_recursion(4);
    print_recursion(10);
}