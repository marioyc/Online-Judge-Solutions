#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define MAXV 30001
#define MAXE 100000

bool can[MAXV];
vector<int> L[MAXV];

int parent[MAXV];

int Find(int x){
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int x, int y){
    x = Find(x); y = Find(y);
    parent[x] = y;
}

int main(){
    int V,E,N;
    
    scanf("%d %d %d",&V,&E,&N);
    
    for(int i = 0,u,v;i < E;++i){
        scanf("%d %d",&u,&v);
        L[u].push_back(v);
        L[v].push_back(u);
    }
    
    memset(can,true,sizeof can);
    
    for(int i = 0,x;i < N;++i){
        scanf("%d",&x);
        
        can[x] = false;
        
        for(int j = L[x].size() - 1;j >= 0;--j)
            can[ L[x][j] ] = false;
    }
    
    for(int i = 1;i <= V;++i)
        parent[i] = i;
    
    for(int i = 1;i <= V;++i){
        if(can[i])
            for(int j = L[i].size() - 1;j >= 0;--j)
                if(can[ L[i][j] ]) Union(i,L[i][j]);
    }
    
    int ans = 0;
    
    for(int i = 1;i <= V;++i)
        if(Find(i) != Find(1)) ++ans;
    
    printf("%d\n",ans);
    
    return 0;
}
