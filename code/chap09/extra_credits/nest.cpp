/*base case is 0
This was written by call number 1
 This was written by call number 2
  This was written by call number 3
   This was written by call number 4
   This was ALSO written by call number 4
  This was AlSO written by call number 3
 This was ALSO written by call number 2
This was ALSO written by call number 1
*/

//void print_tree(int n) {
    /* Trial 1:
    if (n==0) {return;}
    std::cout<<"This was written by call number " << n << std::endl;
    print_tree(n-1);
    std::cout<<"This ALSO written by call number " << n << std::endl;
    */
    
    // NOTES:

    // the above block of code got the results but it was reversed,
    // started with call number 4 and ended at 1, then reversed it with ALSOs from 1 to 4
    // so to reverse it to correct order, base case where recursion ends has to be 4 instead of 0
    // to do that though, going to need a new variable to be the index for the starting position
//}

#include <iostream>
#include <cassert>
#include <string>

void print_tree(int startindex,int n) {
    if (startindex>n) {     //using 4 as the ending point rather than 0
        return;
    }
    else {
        //printing written by call number as you enter recursion
        std::cout<< std::string(startindex,' ') << "This was written by call number " << startindex << std::endl;
        //recursion step
        print_tree(startindex+1,n);
        //exiting the recursion 1 by 1 printing written ALSO by call number in reverse as you exit
        std::cout<< std::string(startindex,' ') << "This ALSO written by call number " << startindex << std::endl;
    }     
       
}

int main() {
    print_tree(1,2); 
}