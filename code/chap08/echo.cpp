#include <queue>
#include <iostream>
/** Implement echo program:
 * given and input x, print x to stdout
 * must use queue & putchar to print on to stdout
 **/

int main(int argc, char *argv[]){

    std::queue<char> letters;
    std::string word = argv[1];
    //put word in queue
    for(uint i=0; i<word.length(); i++){
        letters.push(word[i]);
    }
    while(!letters.empty()){
        std::putchar(letters.front());
        letters.pop();
    }

    std::putchar('\n');

    return 0;
}