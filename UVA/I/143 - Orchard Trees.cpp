#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const double eps=1e-9;

struct point{
    double x,y;
    
    point(){
    }
    
    point(double _x, double _y){
        x=_x; y=_y;
    }
};

double signed_area(const point &p1, const point &p2, const point &p3){
    return (p1.x*p2.y+p2.x*p3.y+p3.x*p1.y-p1.y*p2.x-p2.y*p3.x-p3.y*p1.x)/2;
}

bool ccw(const point &p1, const point &p2, const point &p3){
    return signed_area(p1,p2,p3)>-eps;
}

bool InConvexPolygon(point P, const vector<point> &poly){
    for(int i=1;i<3;i++)
        if(!ccw(poly[i-1],poly[i],P))
            return false;
    
    if(!ccw(poly[2],poly[0],P)) return false;
    
    return true;
}

int main(){
    vector<point> poly(3);
    double x1,y1,x2,y2,x3,y3;
    int lox,hix,loy,hiy,cont;
    
    while(1){
        scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3);
        if(x1==0 && y1==0 && x2==0 && y2==0 && x3==0 && y3==0) break;
        
        poly[0]=point(x1,y1);
        poly[1]=point(x2,y2);
        poly[2]=point(x3,y3);
        
        if(!ccw(poly[0],poly[1],poly[2])) swap(poly[0],poly[2]);
        
        lox=min(ceil(x1),min(ceil(x2),ceil(x3)));
        lox=max(lox,1);
        hix=max(floor(x1),max(floor(x2),floor(x3)));
        hix=min(hix,99);
        loy=min(ceil(y1),min(ceil(y2),ceil(y3)));
        loy=max(loy,1);
        hiy=max(floor(y1),max(floor(y2),floor(y3)));
        hiy=min(hiy,99);
        
        cont=0;
        
        for(int i=lox,j;i<=hix;i++){
            j=loy;
            while(!InConvexPolygon(point(i,j),poly) && j<=hiy) j++;
            for(;j<=hiy;j++)
                if(InConvexPolygon(point(i,j),poly)) cont++;
                else break;
        }
        
        printf("%4d\n",cont);
    }
    
    return 0;
}
