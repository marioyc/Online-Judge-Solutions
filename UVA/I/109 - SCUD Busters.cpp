#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const double eps=1e-9;

struct point{
    int x,y;
    
    point(){
    }
    
    point(const int _x, const int _y){
        x=_x; y=_y;
    }
    
    bool operator < (const point &p) const{
        if(x!=p.x) return x<p.x;
        return y<p.y;
    }
};

bool ccw(const point &p1, const point &p2, const point &p3){
    return (p1.x*p2.y+p2.x*p3.y+p3.x*p1.y-p1.y*p2.x-p2.y*p3.x-p3.y*p1.x)>0;
}

vector<point> ConvexHull_MonotoneChain(vector<point> &P){
    sort(P.begin(),P.end());
    
    int n=P.size(),k=0;
    point H[2*n];
    
    for(int i=0;i<n;i++){
        while(k>=2 && !ccw(H[k-2],H[k-1],P[i])) k--;
        H[k++]=P[i];
    }
    
    for(int i=n-2,t=k;i>=0;i--){
        while(k>t && !ccw(H[k-2],H[k-1],P[i])) k--;
        H[k++]=P[i];
    }
    
    return vector<point> (H,H+k-1);
}

bool PointInsidePolygon(const point P, const vector<point> &poly){
    bool in=0;
    int n=poly.size();
    
    for(int i=0,j=n-1;i<n;j=i++){
        if((poly[i].y <= P.y && P.y < poly[j].y) || (poly[j].y <= P.y && P.y < poly[i].y)){
            if(P.x-eps < (poly[j].x-poly[i].x)*(P.y-poly[i].y)*1.0/(poly[j].y-poly[i].y)+poly[i].x) in^=1;
        }
    }
    
    return in;
}

double signed_area(const vector<point> &poly){
    int n=poly.size();
    int S=0;
    
    for(int i=1;i<n;i++) S+=poly[i].x*(poly[i+1<n? i+1:i+1-n].y-poly[i-1].y);
    S+=poly[0].x*(poly[1].y-poly[n-1].y);
    
    return S/2.0;
}

int main(){
    int N,x,y,n=0;
    
    vector< vector<point> > L;
    vector<point> aux,aux2;
    
    while(1){
        scanf("%d",&N);
        if(N==-1) break;
        n++;
        
        aux.clear();
        for(int i=0;i<N;i++){
            scanf("%d %d",&x,&y);
            aux.push_back(point(x,y));
        }
        
        aux2.clear();
        aux2=ConvexHull_MonotoneChain(aux);
        L.push_back(aux2);
    }
    
    bool valid[n];
    memset(valid,true,sizeof(valid));
    
    while(scanf("%d %d",&x,&y)==2){
        for(int i=0;i<n;i++){
            if(!valid[i]) continue;
            if(PointInsidePolygon(point(x,y),L[i])){
                valid[i]=false;
                break;
            }
        }
    }
    
    double S=0;
    for(int i=0;i<n;i++) if(!valid[i]) S+=fabs(signed_area(L[i]));
    
    printf("%.2f\n",S);
    
    return 0;
}
