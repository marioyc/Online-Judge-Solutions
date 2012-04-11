#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXV 100000
#define MAXE 400000

int to[MAXE],nxt[MAXE],last[MAXV],E;
int level[MAXV],par[MAXV],low[MAXV];
bool visited[MAXV],bridge[MAXV];

void add_edge(int u, int v){
    to[E] = v; nxt[E] = last[u]; last[u] = E++;
    to[E] = u; nxt[E] = last[v]; last[v] = E++;
}

int bridges;

void dfs(int cur, int lvl){
    visited[cur] = true;
    level[cur] = low[cur] = lvl;
    bool rep = false;
    
    for(int e = last[cur];e != -1;e = nxt[e]){
        if(to[e] == par[cur] && !rep) rep = true;
        else if(visited[ to[e] ]) low[cur] = min(low[cur],level[ to[e] ]);
        else{
            par[ to[e] ] = cur;
            dfs(to[e],lvl + 1);
            low[cur] = min(low[cur],low[ to[e] ]);
            
            if(low[ to[e] ] > lvl){
                bridge[ to[e] ] = true;
                ++bridges;
            }
        }
    }
}

void update(int u, int v){
    if(level[u] < level[v]) swap(u,v);
    
    while(level[u] != level[v]){
        if(bridge[u]){
            --bridges;
            bridge[u] = false;
        }
        
        u = par[u];
    }
    
    while(u != v){
        if(bridge[u]){
            --bridges;
            bridge[u] = false;
        }
        
        if(bridge[v]){
            --bridges;
            bridge[v] = false;
        }
        
        u = par[u];
        v = par[v];
    }
}

int main(){
    int tc = 1,N,M,Q;
    
    while(true){
        scanf("%d %d",&N,&M);
        if(N == 0) break;
        
        memset(last,-1,sizeof last);
        E = 0;
        
        for(int i = 0,u,v;i < M;++i){
            scanf("%d %d",&u,&v);
            add_edge(u - 1,v - 1);
        }
        
        memset(visited,false,sizeof visited);
        memset(bridge,false,sizeof bridge);
        par[0] = -1;
        bridges = 0;
        dfs(0,0);
        
        printf("Case %d:\n",tc++);
        scanf("%d",&Q);
        
        for(int q = 0,u,v;q < Q;++q){
            scanf("%d %d",&u,&v);
            update(u - 1,v - 1);
            
            printf("%d\n",bridges);
        }
        
        printf("\n");
    }
    
    return 0;
}
