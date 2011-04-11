#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int parent[10000],depth[10000];

void Make_Set(int x){
    parent[x] = x;
    depth[x] = 0;
}

int Find(int x){
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int u, int v){
    u = Find(u); v = Find(v);
    if(u == v) return;
    
    if(depth[u] < depth[v]){
        parent[u] = v;
    }else{
        parent[v] = u;
        if(depth[u] == depth[v]) ++depth[u];
    }
}

int main(){
    int u,v,N = 0,deg[10000];
    memset(deg,0,sizeof(deg));
    
    for(int i = 0;i < 10000;++i) Make_Set(i);
    
    while(scanf("%d %d",&u,&v) == 2){
        N = max(N,max(u,v));
        --u; --v;
        Union(u,v);
        ++deg[u]; ++deg[v];
    }
    
    int cont[10000];
    memset(cont,0,sizeof(cont));
    
    for(int i = 0;i < N;++i) cont[Find(i)] += deg[i];
    
    bool odds = false;
    for(int i = 0;i < N;++i) if(cont[i] & 2) odds = true;
    
    if(odds) puts("0");
    else puts("1");
    
    return 0;
}
