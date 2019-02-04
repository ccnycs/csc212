#include <iostream>
#include <string>
#include <cmath>

class Point{
    public:
        Point(double nx=0, double ny=0, std::string ncolor="None");
        std::string get_color();
        double distance(Point);
        double getX(){return x;}
        double getY(){return y;}
    private:
        std::string color;
        double x;
        double y;
};
