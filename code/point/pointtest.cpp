#include <iostream>
#include <string>
#include <cmath>

#include "point.h"

using namespace std;
using namespace Point;

int main(){
	//create point
	string color = "yellow";
    Point p1(0,0, color);
    //cout<<p1.x<<" "<<p1.y<<endl;
	int t=1;
	p1.updatePos(exp(.01*t)*cos(t),exp(0.1*t)*sin(t));
	//cout<<p1.x<<" "<<p1.y<<endl;
	
   /**
	for(int t=1; t<200; t++){
		p1.updatePos(exp(.01*t)*cos(t),exp(0.1*t)*sin(t));
		cout<<p1.x<<" "<<p1.y<<endl;
	}**/
	
	//create second point
	Point p2(1,1, "blue");
   //cout<<p2.x<<" "<<p2.y<<endl;
	cout<<"Equal? "<<p1.equal(p2)<<endl;
    cout<<"Equal? "<<(p1==p2)<<endl;
	//assign
	Point p3 = p2;
	//cout<<"3==2:"<<(p3==p2)<<endl;
	cout<<"Equal? "<<p2.equal(p3)<<endl;
	
	Point p4(1,1, "blue");
	//cout<<"3==4:"<<(p3==p4)<<endl;
	cout<<"Equal? "<<p4.equal(p3)<<endl;
   
    //cout<<"Distance "<<distance(p3, p4)<<endl;
    cout<<"Distance "<<::distance(p3, p4)<<endl;
   

   
    return 0;
}