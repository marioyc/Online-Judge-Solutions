#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct edge{
    int u,v,d2;
    
    edge(){}
    
    bool operator < (edge X)const{
        return d2 < X.d2;
    }
}E[499500];

int parent[1000];

int Find(int x){
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int x, int y){
    x = Find(x); y = Find(y);
    parent[x] = y;
}

int main(){
    int N,x[1000],y[1000];
    
    while(true){
        scanf("%d",&N);
        
        if(N == 0) break;
        
        for(int i = 0;i < N;++i)
            scanf("%d %d",&x[i],&y[i]);
        
        int sz = 0;
        
        for(int i = 0;i < N;++i){
            for(int j = i + 1;j < N;++j){
                E[sz].u = i; E[sz].v = j;
                E[sz].d2 = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
                ++sz;
            }
        }
        
        sort(E,E + sz);
        
        for(int i = 0;i < N;++i)
            parent[i] = i;
        
        double ans = 0;
        
        for(int i = 0,ne = 0;i < sz && ne < N - 1;++i){
            if(Find(E[i].u) != Find(E[i].v)){
                Union(E[i].u,E[i].v);
                ans += sqrt(E[i].d2);
                ++ne;
            }
        }
        
        printf("%.2f\n",ans);
    }
    
    return 0;
}
