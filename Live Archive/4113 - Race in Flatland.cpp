#include <cstdio>
#include <cmath>

using namespace std;

double eps = 1e-8;

bool ccw(double ax, double ay, double bx, double by, double cx, double cy){
    return (ax * by + bx * cy + cx * ay - ay * bx - by * cx - cy * ax) >= -eps;
}

double R;

long double solve(double x1, double y1, double x2, double y2, double x3, double y3){
    double c2 = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);
    double a2 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    double b2 = (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2);
    
    long double alpha = acos((a2 + b2 - c2) / 2 / sqrt(a2) / sqrt(b2)) / 2;
    
    if(ccw(x3,y3,x2,y2,x1,y1)) return 2 * R / tan(alpha);
    return -2 * R / tan(alpha);
}

int main(){
    int n;
    double x[100],y[100];
    
    while(scanf("%lf %d",&R,&n) == 2){
        for(int i = 0;i < n;++i)
            scanf("%lf %lf",&x[i],&y[i]);
        
        long double ans = 0;
        
        for(int i = 2;i < n;++i)
            ans += solve(x[i - 2],y[i - 2],x[i - 1],y[i - 1],x[i],y[i]);
        
        printf("%d\n\n",(int)round(abs(ans)));
    }
    
    return 0;
}
