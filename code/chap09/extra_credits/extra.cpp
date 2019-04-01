/* 
Name: Peter Ye
Date: 3/31/2019
Extra Credit: Recursion 
*/

#include <iostream>

void recursive_tabs(int n, int counts = 0){
    if(n==counts){
        return;
    }
    std::cout<< "\t";
    recursive_tabs(n, counts+1);
}


void recursive_func(int num, int count_tab = 1){
    if(num<count_tab){
        return;
    }
    else {
    recursive_tabs(count_tab);
    std::cout << "This was written by call number " << count_tab << ".\n";
    recursive_func(num, count_tab+1);
    recursive_tabs(count_tab);
    std::cout << "This ALSO written by call number " << count_tab << ".\n";
    }
}

int main(){
    int x;
    std::cout << "Number of levels = ";
    std::cin >> x;
    recursive_func(x);

    return 0;
}
