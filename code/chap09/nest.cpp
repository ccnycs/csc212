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

/*base:
This was written by call number 1.
This ALSO written by call number 1.
*/
#include <iostream>
void print_tree(int n){
    if (n==0){return ;}
    std::cout<<"This was written by call number "<<n<<std::endl;
    print_tree(n-1);
        std::cout<<'\t';
    std::cout<<"This ALSO written by call number "<<n<<std::endl;

}

int main(){
    print_tree(3);
    return 0;
};