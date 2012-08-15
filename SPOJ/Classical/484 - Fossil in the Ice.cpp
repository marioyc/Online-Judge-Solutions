#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct point{
    int x,y;
    
    point(){}
    
    long long dist2(point P){
        return (long long)(x - P.x) * (x - P.x) + (long long)(y - P.y) * (y - P.y);
    }
    
    bool operator < (point P)const{
        if(x != P.x) return x < P.x;
        return y < P.y;
    }
}P[100000];

long long area(point a, point b, point c){
    return (long long)a.x * b.y + (long long)b.x * c.y + (long long)c.x * a.y - (long long)a.y * b.x - (long long)b.y * c.x - (long long)c.y * a.x;
}

int N;

vector<point> convex_hull(){
    point H[2 * N];
    sort(P,P + N);
    int sz = 0;
    
    for(int i = 0;i < N;++i){
        while(sz > 2 && area(H[sz - 2],H[sz - 1],P[i]) <= 0) --sz;
        H[sz++] = P[i];
    }
    
    for(int i = N - 2,t = sz;i > 0;--i){
        while(sz > t && area(H[sz - 2],H[sz - 1],P[i]) <= 0) --sz;
        H[sz++] = P[i];
    }
    
    return vector<point>(H,H + (sz - 1));
}

int main(){
    int T;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        for(int i = 0;i < N;++i)
            scanf("%d %d",&P[i].x,&P[i].y);
        
        long long ans = 0;
        
        if(N == 2) ans = P[0].dist2(P[1]);
        else if(N > 2){
            vector<point> H = convex_hull();
            int M = H.size();
            
            
            for(int i = 0,j = 2;i < M;++i){
                while(area(H[i],H[(i + 1) % M],H[j]) < area(H[i],H[(i + 1) % M],H[(j + 1) % M])) j = (j + 1) % M;
                ans = max(ans,H[i].dist2(H[j]));
                ans = max(ans,H[(i + 1) % M].dist2(H[j]));
            }
        }
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
