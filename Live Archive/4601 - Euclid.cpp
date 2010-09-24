#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

struct point{
    double x,y;
    
    point(){}
    
    point(double _x, double _y){
    	x = _x; y = _y;
    }
    
    void read(){
    	cin>>x>>y;
    }
    
    bool isOrigin(){
    	return (x<1e-8 && y<1e-8);
    }
    
    point operator - (point P){
    	return point(x-P.x,y-P.y);
    }
    
    point operator * (double r){
    	return point(r*x,r*y);
    }
    
    point operator + (point P){
    	return point(x+P.x,y+P.y);
    }
}A,B,C,D,E,F;

double area(point a, point b, point c){
    return fabs(a.x*b.y+b.x*c.y+c.x*a.y-a.y*b.x-b.y*c.x-c.y*a.x);
}

int main(){
    while(true){
    	A.read(); B.read(); C.read();
    	D.read(); E.read(); F.read();
    	
    	if(A.isOrigin() && B.isOrigin() && C.isOrigin()
    	    && D.isOrigin() && E.isOrigin() && F.isOrigin())
    	        break;
    	
    	double r = area(D,E,F)/area(A,B,C)/2;
    	
    	point H = A+(C-A)*r;
    	point G = B+(H-A);
    	
    	printf("%.3lf %.3lf %.3lf %.3lf\n",G.x,G.y,H.x,H.y);
    }
    
    return 0;
}
