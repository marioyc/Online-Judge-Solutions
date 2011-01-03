#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAX_V 1000
typedef int edge_cost;
edge_cost INF = INT_MAX;

int V,E,root,prev[MAX_V];
bool adj[MAX_V][MAX_V];
edge_cost G[MAX_V][MAX_V],MCA;
bool visited[MAX_V],circle[MAX_V];

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

int exist_circle(){
    prev[root] = root;
    
    for(int i = 0;i<V;++i){
        if(!circle[i] && i!=root){
            prev[i] = i; G[i][i] = INF;
            
            for(int j = 0;j<V;++j)
                if(!circle[j] && adj[j][i] && G[j][i]<G[prev[i]][i])
                    prev[i] = j;
        }
    }
    
    for(int i = 0,j;i<V;++i){
        if(circle[i]) continue;
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
        circle[i] = true;
    }
    
    for(int i = 0;i<V;++i)
        if(!circle[i] && adj[i][v])
            G[i][v] -= G[prev[v]][v];
    
    for(int j = prev[v];j!=v;j = prev[j]){
        for(int i = 0;i<V;++i){
            if(circle[i]) continue;
            
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
    
    memset(circle,false,sizeof(circle));
    MCA = 0;
    
    int v;
    
    while((v = exist_circle())!=-1)
        update(v);
    
    for(int i = 0;i<V;++i)
        if(i!=root && !circle[i])
            MCA += G[prev[i]][i];
    
    return true;
}

int main(){
    int T,M,a,b,c;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc<=T;++tc){
        scanf("%d %d",&V,&M);
        memset(adj,false,sizeof(adj));
        
        for(int i = 0;i<M;++i){
            scanf("%d %d %d",&a,&b,&c);
            add_edge(a,b,c);
        }
        
        printf("Case #%d: ",tc);
        if(!min_cost_arborescence(0)) printf("Possums!\n");
        else printf("%d\n",MCA);
    }
    
    return 0;
}
