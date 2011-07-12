#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int T,N,M,s,e;
    bool adj[300][300];
    int dist[300][300];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d %d %d",&N,&s,&e,&M);
        
        memset(adj,false,sizeof(adj));
        
        for(int i = 0;i < N;++i){
            dist[i][i] = 0;
            adj[i][i] = true;
        }
        
        for(int i = 0,u,v,w;i < M;++i){
            scanf("%d %d %d",&u,&v,&w);
            
            if(!adj[u][v]) dist[u][v] = w;
            else dist[u][v] = min(dist[u][v],w);
            adj[u][v] = true;
        }
        
        for(int k = 0;k < N;++k) for(int i = 0;i < N;++i) for(int j = 0;j < N;++j){
            if(adj[i][k] && adj[k][j]){
                if(!adj[i][j]) dist[i][j] = dist[i][k] + dist[k][j];
                else dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                adj[i][j] = true;
            }
        }
        
        if(!adj[s][e]) puts("infinity");
        else{
            bool valid = true;
            
            for(int i = 0;i < N;++i){
                if(adj[s][i] && adj[i][e] && dist[i][i] < 0){
                    puts("infinity");
                    valid = false;
                    break;
                }
            }
            
            if(valid) printf("%d\n",dist[s][e]);
        }
    }
    
    return 0;
}
