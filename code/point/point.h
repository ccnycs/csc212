#include <string>
#include <cmath>

   
class Point{
 private:
   double x;
   double y;
 public:
   std::string color;
   Point();
   Point(double x0, double y0);
   Point(double x0, double y0, std::string c0);
   void display();
   void updatePos(double nx, double ny);
   bool equal(Point P);
   bool operator==(Point P);
   friend double distance(Point P1, Point P2);
   friend double slope(Point P1, Point P2);
};

Point::Point(){};

Point::Point(double x0, double y0){
   x = x0;
   y = y0;
}

Point::Point(double x0, double y0, std::string c0){
    x = x0;
    y = y0;
    color = c0;
}
void Point::display(){
   std::cout<<"Point("<<x<<", "<<y<<")"<<std::endl;
}

void Point::updatePos(double nx, double ny){
	x = nx;
	y = ny;
}

bool Point::equal(Point P){
	return ((x==P.x)&&(y==P.y));
}

bool Point::operator==(Point P)
{
   return equal(P);
}

double distance(Point P1, Point P2)
{
   return sqrt(pow(P1.x-P2.x,2.0)+pow(P1.y-P2.y, 2.0));
}

double slope(Point P1, Point P2)
{
   return (P1.y-P2.y)/(P1.x-P2.x);
}
