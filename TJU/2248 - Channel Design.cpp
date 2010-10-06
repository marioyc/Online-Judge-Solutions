#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

#define MAX_V 100
typedef int edge_cost;
edge_cost INF = INT_MAX;

int V,E,root,prev[MAX_V];
bool adj[MAX_V][MAX_V];
edge_cost G[MAX_V][MAX_V],MCA;
bool visited[MAX_V],cycle[MAX_V];

void add_edge(int u, int v, edge_cost c){
    if(adj[u][v]) G[u][v] = min(G[u][v],c);
    else G[u][v] = c;
    adj[u][v] = true;
}

void dfs(int v){
    visited[v] = true;
    
    for(int i = 0;i<V;++i)
        if(!visited[i] && adj[v][i])
            dfs(i);
}

bool check(){
    memset(visited,false,sizeof(visited));
    dfs(root);
    
    for(int i = 0;i<V;++i)
        if(!visited[i])
            return false;
    
    return true;
}

int exist_cycle(){
    prev[root] = root;
    
    for(int i = 0;i<V;++i){
        if(!cycle[i] && i!=root){
            prev[i] = i; G[i][i] = INF;
            
            for(int j = 0;j<V;++j)
                if(!cycle[j] && adj[j][i] && G[j][i]<G[prev[i]][i])
                    prev[i] = j;
        }
    }
    
    for(int i = 0,j;i<V;++i){
        if(cycle[i]) continue;
        memset(visited,false,sizeof(visited));
        
        j = i;
        
        while(!visited[j]){
            visited[j] = true;
            j = prev[j];
        }
        
        if(j==root) continue;
        return j;
    }
    
    return -1;
}

void update(int v){
    MCA += G[prev[v]][v];
    
    for(int i = prev[v];i!=v;i = prev[i]){
        MCA += G[prev[i]][i];
        cycle[i] = true;
    }
    
    for(int i = 0;i<V;++i)
        if(!cycle[i] && adj[i][v])
            G[i][v] -= G[prev[v]][v];
    
    for(int j = prev[v];j!=v;j = prev[j]){
        for(int i = 0;i<V;++i){
            if(cycle[i]) continue;
            
            if(adj[i][j]){
                if(adj[i][v]) G[i][v] = min(G[i][v],G[i][j]-G[prev[j]][j]);
                else G[i][v] = G[i][j]-G[prev[j]][j];
                adj[i][v] = true;
            }
            
            if(adj[j][i]){
                if(adj[v][i]) G[v][i] = min(G[v][i],G[j][i]);
                else G[v][i] = G[j][i];
                adj[v][i] = true;
            }
        }
    }
}

bool min_cost_arborescence(int _root){
    root = _root;
    if(!check()) return false;
    
    memset(cycle,false,sizeof(cycle));
    MCA = 0;
    
    int v;
    
    while((v = exist_cycle())!=-1)
        update(v);
    
    for(int i = 0;i<V;++i)
        if(i!=root && !cycle[i])
            MCA += G[prev[i]][i];
    
    return true;
}

int main(){
    int M,u,v,c;
    
    while(true){
        scanf("%d %d",&V,&M);
        if(V==0) break;
        
        memset(adj,false,sizeof(adj));
        
        for(int i = 0;i<M;++i){
            scanf("%d %d %d",&u,&v,&c);
            add_edge(u-1,v-1,c);
        }
        
        if(!min_cost_arborescence(0)) printf("impossible\n");
        else printf("%d\n",MCA);
    }
    
    return 0;
}
