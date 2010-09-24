#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct point{
    int x,y;
    
    point(){
    }
    
    point(const int _x, const int _y){
        x=_x; y=_y;
    }
    
    point operator - (const point &p) const{
        return point(x-p.x,y-p.y);
    }
};

int AreaBy2(const vector<point> &poly){
    int n=poly.size();
    int S=0;
    
    for(int i=1;i<n;i++) S+=poly[i].x*(poly[i+1<n? i+1:i+1-n].y-poly[i-1].y);
    S+=poly[0].x*(poly[1].y-poly[n-1].y);
    
    if(S<0) return -S;
    return S;
}

int IntegerPointsOnSegment(const point &P1, const point &P2){
    point P=P1-P2;
    P.x=abs(P.x); P.y=abs(P.y);
    
    if(P.x==0) return P.y-1;
    if(P.y==0) return P.x-1;
    return (__gcd(P.x,P.y))-1;
}

int main(){
    int T,N,x,y,dx,dy;
    int S,B,I;
    vector<point> poly;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d",&N);
        
        poly.clear();
        x=0; y=0;
        poly.push_back(point(x,y));
        
        for(int i=0;i<N;i++){
            scanf("%d %d",&dx,&dy);
            x+=dx; y+=dy;
            poly.push_back(point(x,y));
        }
        
        S=AreaBy2(poly); B=N;
        for(int i=0,j=N-1;i<N;j=i++) B+=IntegerPointsOnSegment(poly[j],poly[i]);
        
        printf("Scenario #%d:\n%d %d %.1f\n\n",tc,(S-B+2)>>1,B,S/2.0);
    }
    
    return 0;
}
