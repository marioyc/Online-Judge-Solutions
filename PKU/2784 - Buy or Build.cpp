#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int sz[8],cost[8],L[8][1000];
int x[1000],y[1000],parent[1001];

int Find(int x){
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int x, int y){
    x = Find(x); y = Find(y);
    parent[x] = y;
}

struct edge{
    int u,v,w;
    
    edge(){}
    edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w){}
    
    bool operator < (edge X)const{
        return w < X.w;
    }
}e[1000000];

int main(){
    int n,m;
    
    scanf("%d %d",&n,&m);
    
    for(int i = 0;i < m;++i){
        scanf("%d %d",&sz[i],&cost[i]);
        
        for(int j = 0;j < sz[i];++j)
            scanf("%d",&L[i][j]);
    }
    
    for(int i = 0;i < n;++i)
        scanf("%d %d",&x[i],&y[i]);
    
    int E = 0;
    
    for(int i = 0;i < n;++i)
        for(int j = i + 1;j < n;++j)
            e[E++] = edge(i + 1,j + 1,(x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
    
    sort(e,e + E);
    
    long long ans = (1LL << 60);
    
    for(int mask = 0;mask < (1 << m);++mask){
        long long aux = 0;
        
        for(int i = 1;i <= n;++i)
            parent[i] = i;
        
        for(int i = 0;i < m;++i){
            if(mask & (1 << i)){
                aux += cost[i];
                
                for(int j = sz[i] - 1;j > 0;--j)
                    Union(L[i][j],L[i][0]);
            }
        }
        
        for(int i = 0;i < E;++i){
            if(Find(e[i].u) != Find(e[i].v)){
                aux += e[i].w;
                Union(e[i].u,e[i].v);
            }
        }
        
        ans = min(ans,aux);
    }
    
    printf("%d\n",ans);
    
    return 0;
}
