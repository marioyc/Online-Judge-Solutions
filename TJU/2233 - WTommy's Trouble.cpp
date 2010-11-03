#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#define MAX_V 10000

int V, num_scc, scc[MAX_V];
vector<int> G[MAX_V],GT[MAX_V];
bool visited[MAX_V];
stack<int> S;
queue<int> Q;

void dfs(int v){
    visited[v] = true;
    for(int i=G[v].size()-1;i>=0;--i) if(!visited[G[v][i]]) dfs(G[v][i]);
    S.push(v);
}

void bfs(int v){
     Q.push(v);
     visited[v] = true;
     int aux;
     
     while(!Q.empty()){
          aux = Q.front();
          scc[aux] = num_scc;
          Q.pop();
          
          for(int i=GT[aux].size()-1;i>=0;i--){
               if(!visited[GT[aux][i]]){
                    Q.push(GT[aux][i]);
                    visited[GT[aux][i]] = true;
               }
          }
     }
}

void SCC(){
     memset(visited,false,sizeof(visited));
     for(int i=0;i<V;++i) if(!visited[i]) dfs(i);
     
     num_scc = 0;
     int aux;
     memset(visited,false,sizeof(visited));
     
     while(!S.empty()){
        aux = S.top();
        S.pop();
        
        if(!visited[aux]){
            bfs(aux);
            ++num_scc;
        }
    }
}

int main(){
    int N,M,u,v,t[MAX_V],in[MAX_V],cost[MAX_V];
    
    while(true){
        scanf("%d %d",&N,&M);
        if(N==0 && M==0) break;
        
        for(int i=0;i<N;++i){
            scanf("%d",&t[i]);
            G[i].clear();
            GT[i].clear();
        }
        
        for(int i=0;i<M;++i){
            scanf("%d %d",&u,&v);
            --u; --v;
            
            G[u].push_back(v);
            GT[v].push_back(u);
        }
        
        V = N;
        SCC();
        
        memset(cost,-1,sizeof(cost));
        for(int i=0;i<N;++i) if(cost[scc[i]]==-1 || t[i]<cost[scc[i]]) cost[scc[i]] = t[i];
        
        memset(in,0,sizeof(in));
        for(int i=0;i<N;++i) for(int j=G[i].size()-1;j>=0;--j){
            v = G[i][j];
            if(scc[i]!=scc[v]) ++in[scc[v]];
        }
        
        int ans = 0;
        for(int i=0;i<num_scc;++i) if(in[i]==0) ans += cost[i];
        
        printf("%d\n",ans);
    }
    
    return 0;
}
