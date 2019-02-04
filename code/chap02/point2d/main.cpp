#include <iostream>
#include "point.h"

int main(){
    Point P1(2, 3, "yellow");
    Point P2;
    std::cout<<P2.getX()<<" "<<P2.getY()<<std::endl;
    std::cout<<P2.distance(P1)<<std::endl;
    return 0;
}