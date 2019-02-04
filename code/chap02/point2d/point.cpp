#include "point.h"

Point::Point(double nx, double ny, std::string ncolor){
    x = nx;
    y = ny;
    color = ncolor;
}

std::string Point::get_color(){
    return color;
} 

double Point::distance(Point P){
    return std::sqrt(std::pow(x - P.x, 2) + std::pow(y-P.y,2));
}
