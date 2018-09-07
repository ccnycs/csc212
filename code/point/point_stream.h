#include <ostream>
#include <istream>
   
class Point{
 private:
    int x;
    int y;
 public:
   Point();
   Point(int nx, int ny);
   friend std::istream& 
      operator>> (std::istream &input, Point &P);
   friend std::ostream& 
      operator<< (std::ostream &output, Point &P);
};

Point::Point(){};
Point::Point(int nx, int ny){
    x = nx;
    y = ny;
}

std::istream& operator>> (std::istream &input, Point &P){
    input >> P.x;
    input >> P.y;
    return input;
}
std::ostream& operator<< (std::ostream &output, Point &P){
    output << "(" << P.x << ", " << P.y <<")";
    return output;
}
