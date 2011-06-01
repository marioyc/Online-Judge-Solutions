#include <cstdio>
#include <cmath>

using namespace std;

struct point{
    double x,y;
    
    point(){}
    
    point(double _x, double _y){
        x = _x; y = _y;
    }
    
    point(int _x, int _y){
        x = _x; y = _y;
    }
    
    point operator + (point P){
        return point(x + P.x, y + P.y);
    }
    
    point operator - (point P){
        return point(x - P.x, y - P.y);
    }
    
    point operator * (double k){
        return point(k * x, k * y);
    }
    
    double abs(){
        return sqrt(x * x + y * y);
    }
};

double eps = 1e-9;

bool solve(point A, point B, point C, point &ret1, point &ret2){
    double a = (B - C).abs(), b = (C - A).abs(), c = (A - B).abs();
    double X = (a + b + c) / 2;
    double Y = sqrt(X * X - 2 * a * b);
    double L1 = (X - Y) / 2, L2 = (X + Y) / 2;
    
    if(L1 <= a + eps && L2 <= b + eps){
        ret1 = C + (B - C) * (L1 / a);
        ret2 = C + (A - C) * (L2 / b);
        return true;
    }
    
    if(L2 <= a + eps && L1 <= b + eps){
        ret1 = C + (B - C) * (L2 / a);
        ret2 = C + (A - C) * (L1 / b);
        return true;
    }
    
    return false;
}

int main(){
    int x1,y1,x2,y2,x3,y3;
    
    scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
    
    point A(x1,y1), B(x2,y2), C(x3,y3), ans1,ans2;
    
    bool possible = (solve(A,B,C,ans1,ans2) || solve(B,C,A,ans1,ans2) || solve(C,A,B,ans1,ans2));
    solve(A,B,C,ans1,ans2);
    solve(B,C,A,ans1,ans2);
    solve(C,A,B,ans1,ans2);
    
    if(!possible) puts("NO");
    else{
        puts("YES");
        printf("%.10f %.10f\n",ans1.x,ans1.y);
        printf("%.10f %.10f\n",ans2.x,ans2.y);
    }
    
    return 0;
}
