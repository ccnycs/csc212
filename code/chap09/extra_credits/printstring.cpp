#include <iostream>
#include <string>

void print_string(int n, int i = 1){
    int space = 1;
    if(n == 0 || n < 0){return;}
    if(i<=n){
        while(space < i){
            std::cout<<"    ";
            space++;
        }
        std::cout<<"this was  called by call number "<<i<<std::endl;
        print_string(n,i+1);
        space = 1;
        while(space < i){
            std::cout<<"    ";
            space++;
        }
        std::cout<<"this ALSO called by call number "<<i<<std::endl;

    }
}

int main(){
    int i;
    std::cout<<"enter a number"<<std::endl;
    std::cin>>i;
    print_string(i);
    
    return 0;
}