#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 200005

struct edge{
    int u,v,w;
    
    edge(){}
    
    edge(int _u, int _v, int _w):
        u(_u),v(_v),w(_w){}
    
    bool operator < (edge X)const{
        return w > X.w;
    }
}e[MAXN];

int parent[MAXN],cont[MAXN];
long long lazy[MAXN];

int Find(int x){
    if(parent[x] != x){
        int r = Find(parent[x]);
        if(r != parent[x]) lazy[x] += lazy[ parent[x] ];
        parent[x] = r;
    }
    
    return parent[x];
}

void Union(int u, int v, int w){
    u = Find(u);
    v = Find(v);
    
    if(cont[v] > cont[u]) swap(u,v);
    
    lazy[v] += (long long)(cont[u] - cont[v]) * w - lazy[u];
    lazy[u] += (long long)cont[v] * w;
    cont[u] += cont[v];
    parent[v] = u;
}

int main(){
    int N;
    
    while(scanf("%d",&N) == 1){
        for(int i = 0;i < N - 1;++i)
            scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
        
        for(int i = 1;i <= N;++i){
            parent[i] = i;
            cont[i] = 1;
            lazy[i] = 0;
        }
        
        sort(e,e + (N - 1));
        
        for(int i = 0;i < N - 1;++i)
            Union(e[i].u,e[i].v,e[i].w);
        
        long long ans = 0;
        
        for(int i = 1;i <= N;++i){
            Find(i);
            ans = max(ans,lazy[i] + (parent[i] == i? 0 : lazy[ parent[i] ]));
        }
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
