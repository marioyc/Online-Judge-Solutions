#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

int A[100000],B[100000],V,deg[200000];
vector<int> adj[200000];
bool visited[200000];
set<int> S;
map<int, int> id;
vector<int> aux;

int main(){
    int N,W,tc = 0;
    
    while(true){
        scanf("%d %d",&N,&W);
        if(N == 0) break;
        tc++;
        
        S.clear();
        
        for(int i = 0;i < W;++i){
            scanf("%d %d",&A[i],&B[i]);
            
            S.insert(A[i]);
            S.insert(B[i]);
        }
        
        aux = vector<int>(S.begin(),S.end());
        id.clear();
        V = aux.size();
        
        for(int i = 0;i < V;++i) id[aux[i]] = i;
        for(int i = 0;i < V;++i) adj[i].clear();
        
        for(int i = 0;i < W;++i){
            A[i] = id[A[i]];
            B[i] = id[B[i]];
            adj[A[i]].push_back(B[i]);
            adj[B[i]].push_back(A[i]);
        }
        
        bool ok = true;
        
        for(int i = 0;i < V;++i){
            S = set<int>(adj[i].begin(),adj[i].end());
            adj[i] = vector<int>(S.begin(),S.end());
            deg[i] = adj[i].size();
            if(deg[i] > 2) ok = false;
        }
        
        if(!ok) puts("N");
        else{
            memset(visited,false,sizeof(visited));
            
            for(int i = 0;i < V;++i){
                if(!visited[i] && deg[i] == 1){
                    int cur = adj[i][0];
                    visited[i] = true;
                    
                    do{
                        visited[cur] = true;
                        if(deg[cur] == 1) break;
                        int nxt = visited[adj[cur][0]]? adj[cur][1] : adj[cur][0];
                        cur = nxt;
                    }while(true);
                }
            }
            
            int cont = 0;
            for(int i = 0;i < V;++i) if(visited[i]) ++cont;
            
            if(cont == 0 && V == N){
                int cur = adj[0][0],u,v;
                visited[0] = true;
                
                do{
                    u = adj[cur][0];
                    v = adj[cur][1];
                    visited[cur] = true;
                    
                    if(!visited[u]) cur = u;
                    else cur = v;
                }while(!visited[u] || !visited[v]);
                
                for(int i = 0;i < V;++i) if(visited[i]) ++cont;
                
                if(cont == N) puts("Y");
                else puts("N");
            }else if(cont < V || !ok) puts("N");
            else puts("Y");
        }
    }
    
    return 0;
}
