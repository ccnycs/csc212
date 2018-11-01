#include <iostream>
#include <queue>
#include <string>

int main(){
    std::string myword;
    std::cout<<"Enter a word: ";
    std::cin>>myword;
    std::queue<char> letters;

    for(int i =0; i<myword.size(); i++){
        letters.push(myword[i]);
    }

    while(!letters.empty()){
        std::cout<<letters.front();
        letters.pop();
    }
    std::cout<<std::endl;
    return 0;
/***
    declare a queue of characters
    while (there are more characters of the word to read)
        read a chaarcter
        push the character into the queue
    while (the queue is not empty)
        write the front character to the screen
        remove the front character from the queue
***/

}