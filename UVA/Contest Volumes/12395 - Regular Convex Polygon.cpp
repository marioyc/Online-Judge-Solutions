#include <cstdio>
#include <cmath>

using namespace std;

double eps = 1e-7;

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
    
    double abs(){
        return sqrt(x*x + y*y);
    }
}P1,P2,P3;

point get_center(point A, point B, point C){
    point v1 = (B - A).perp(),v2 = C - A;
    point m1 = (A + B) * 0.5;
    point m2 = (A + C) * 0.5;
    double k = (m2 - m1).dot(v2) / v1.dot(v2);
    return m1 + v1 * k;
}

int main(){
    while(scanf("%lf %lf %lf %lf %lf %lf",&P1.x,&P1.y,&P2.x,&P2.y,&P3.x,&P3.y) == 6){
        point O = get_center(P1,P2,P3);
        
        double R = (P1 - O).abs();
        double a = asin(fmin(1.0,(P1 - P2).abs() / 2 / R));
        double b = asin(fmin(1.0,(P1 - P3).abs() / 2 / R));
        
        for(int i = 3;i <= 1000;++i){
            double rema = a - round(a / (M_PI / i)) * (M_PI / i);
            double remb = b - round(b / (M_PI / i)) * (M_PI / i);
            
            if(fabs(rema) < eps && fabs(remb) < eps){
                printf("%d\n",i);
                break;
            }
        }
    }
    
    return 0;
}
