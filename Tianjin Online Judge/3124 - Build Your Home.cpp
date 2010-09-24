#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

const double eps=1e-9;

struct point{
    double x,y;
    
    point(){
    }
    
    point(const double _x, const double _y){
        x=_x; y=_y;
    }
};

double signed_area(const vector<point> &poly){
    int n=poly.size();
    if(n<3) return 0;
    
    double S=0;
    
    for(int i=1;i<n;i++) S+=poly[i].x*(poly[i+1<n? i+1:i+1-n].y-poly[i-1].y);
    S+=poly[0].x*(poly[1].y-poly[n-1].y);
    S/=2;
    
    return S;
}

int main(){
    int n;
    double x,y;
    vector<point> poly;
    
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        
        poly.clear();
        
        for(int i=0;i<n;i++){
            scanf("%lf %lf",&x,&y);
            poly.push_back(point(x,y));
        }
        
        printf("%.0f\n",fabs(signed_area(poly)));
    }
    
    return 0;
}
