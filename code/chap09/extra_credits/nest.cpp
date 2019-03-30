/*
This was written by call number 1.
    This was written by call number 2.
        This was written by call number 3.
            This was written by call number 4.
            This ALSO written by call number 4.
        This ALSO written by call number 3.
    This ALSO written by call number 2.
This ALSO written by call number 1.
*/
/*
This was written by call number 1.
This ALSO written by call number 1.
*/
#include <iostream>

void print_bottom(int n){
    if(n==0){return;}
    for(int i=1;i<n;i++){
        std::cout<<'\t';
    }
    std::cout<<"This ALSO written by call number "<<n<<std::endl;
    print_bottom(n-1);
}
void print_tree(int n){
    if(n==0){return;}
    print_tree(n-1);
    if(n==1){std::cout<<"This was written by call number "<<n<<std::endl;}
    else{
        for(int i=1;i<n;i++){
            std::cout<<'\t';
        }
        std::cout<<"This was written by call number "<<n<<std::endl;
    }
}

int main(){
    print_tree(5);
    print_bottom(5);
    return 0;
}
