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

void print_tree(uint n, uint m=1){
    if (n==m-1){return ;}
    for(uint i=1;i<m;i++)
    {
        std::cout<<"\t";
    }
    std::cout<<"This was written by call number "<<m<<std::endl;
    print_tree(n,m+1); 
    for(uint i=1;i<m;i++)
    {
        std::cout<<"\t";
    }  
    std::cout<<"This ALSO written by call number "<<m<<std::endl;
 
}

int main(){
    int n;
    std::cout<<"Enter a number N to print the tree of 2N rows: ";
    std::cin>>n;
    print_tree(n);
    return 0;
};