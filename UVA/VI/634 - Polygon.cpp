#include <cstdio>
#include <vector>

using namespace std;

double eps=1e-9;

struct point{
    double x,y;
    
    point(){
    }
    
    point(double _x, double _y){
        x=_x; y=_y;
    }
};

bool PointInsidePolygon(const point P, const vector<point> &poly){
    bool in=0;
    int n=poly.size();
    
    for(int i=0,j=n-1;i<n;j=i++){
        if((poly[i].y <= P.y+eps && P.y < poly[j].y) || (poly[j].y <= P.y+eps && P.y < poly[i].y)){
            if(P.x-eps < (poly[j].x-poly[i].x)*(P.y-poly[i].y)/(poly[j].y-poly[i].y)+poly[i].x) in^=1;
        }
    }
    
    return in;
}

int main(){
    int N;
    double x,y;
    vector<point> poly;
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        
        poly.clear();
        for(int i=0;i<N;i++){
            scanf("%lf %lf",&x,&y);
            poly.push_back(point(x,y));
        }
        
        scanf("%lf %lf",&x,&y);
        
        if(PointInsidePolygon(point(x,y),poly)) printf("T\n");
        else printf("F\n");
    }
    
    return 0;
}
