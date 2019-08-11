#include <iostream>
#include <string>

void print_string(int n, int i = 1, std::string space = ""){
    
    if(n == 0 || n < 0){return;}
    if(i<=n){
        if(i>1){
        space += "   ";
        }
        std::cout<<space;
        std::cout<<"this was written by call number "<<i<<std::endl;
        print_string(n,i+1,space);
        std::cout<<space;
        std::cout<<"this ALSO written by call number "<<i<<std::endl;

    }
}

int main(){
    int i;
    std::cout<<"enter a number"<<std::endl;
    std::cin>>i;
    print_string(i);
    
    return 0;
}