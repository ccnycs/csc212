/* Compute Fibonacci Sequence
Base Case: 𝐹_0=0, 𝐹_1=1
Recursive Case: 𝐹_𝑛=𝐹_𝑛−1+𝐹_𝑛−2
*/
#include <cassert>
int fib(int n){
    if (n==1 || n==0){return n;} 
    return fib(n-1) + fib(n-2);
}

int main(){
    assert(fib(0)==0);
    assert(fib(1)==1);
    assert(fib(2)==1);
    assert(fib(3)==2);
    assert(fib(4)==3);
    
}
