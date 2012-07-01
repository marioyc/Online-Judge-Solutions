#include <cstdio>
#include <cmath>

using namespace std;

struct point{
    double x,y;
    
    point(){}
    point(double _x, double _y) : x(_x), y(_y){}
    
    point operator - (point P){
        return point(x - P.x,y - P.y);
    }
    
    point operator + (point P){
        return point(x + P.x,y + P.y);
    }
    
    point operator * (double k){
        return point(k * x,k * y);
    }
    
    point perp(){
        return point(-y,x);
    }
    
    double dot(point P){
        return x * P.x + y * P.y;
    }
};

double area(int x1, int y1, int x2, int y2, int x3, int y3){
    return fabs(0.5 * (x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1));
}

point get_center(point A, point B, point C){
    point v1 = (B - A).perp(),v2 = C - A;
    point m1 = (A + B) * 0.5;
    point m2 = (A + C) * 0.5;
    double k = (m2 - m1).dot(v2) / v1.dot(v2);
    return m1 + v1 * k;
}

int main(){
    int x1,y1,x2,y2,x3,y3;
    double a,b,c,R;
    point O;
    
    while(true){
        scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
        
        if(x1 == -1) break;
        
        a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        b = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
        c = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
        
        R = a * b * c / 8 / area(x1,y1,x2,y2,x3,y3);
        O = get_center(point((x1 + x2) / 2.0,(y1 + y2) / 2.0),point((x2 + x3) / 2.0,(y2 + y3) / 2.0),point((x3 + x1) / 2.0,(y3 + y1) / 2.0));
        
        printf("%.6f %.6f %.6f\n",O.x,O.y,R);
    }
    
    return 0;
}
