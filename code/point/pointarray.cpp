#include <iostream>
#include <cmath>
using namespace std;
class Point{
	int x;
	int y;
};

double distance(Point *p1, Point *p2){
	return sqrt((pow(p1->x,2.0)-pow(p2->x, 2.0))+
				(pow(p1->y,2.0) - pow(p2->y, 2.0)));
	}
int main(){
	Point p = {1, 2};
	cout<<p.x<<" "<<p.y<<endl;
	Point p2 = {0, 0};
	cout<<p2.x<<" "<<p2.y<<endl;
	
	cout<<distance(&p, &p2)<<endl;
	
	Point points[10];
	for (int i=0; i<10; i++){
		Point p(i*2, i*10);
		points[i] = p;
		cout<<points[i].x<<" "<<points[i].y<<endl;
	}
}	