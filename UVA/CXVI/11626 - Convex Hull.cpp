#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct point{
    long long x,y;
    
    point(){
    }
    
    point(const int &_x, const int &_y){
        x=_x; y=_y;
    }
    
    bool operator < (const point &p) const{
        if(x!=p.x) return x<p.x;
        return y<p.y;
    }
};

bool ccw(const point &p1, const point &p2, const point &p3){
    return (p1.x*p2.y+p2.x*p3.y+p3.x*p1.y-p1.y*p2.x-p2.y*p3.x-p3.y*p1.x)>=0;
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

int main(){
    int T,N,x,y;
    char c;
    vector<point> P,H;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d",&N);
        
        P.clear();
        
        for(int i=0;i<N;i++){
            scanf("%d %d %c",&x,&y,&c);
            if(c=='Y') P.push_back(point(x,y));
        }
        
        H=ConvexHull_MonotoneChain(P);
        N=H.size();
        
        printf("%d\n",N);
        for(int i=0;i<N;i++) printf("%lld %lld\n",H[i].x,H[i].y);
    }
    
    return 0;
}
