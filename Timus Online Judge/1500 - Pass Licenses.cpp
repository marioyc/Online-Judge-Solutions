#include <cstdio>
#include <cstring>

using namespace std;

int bitCount(int x){
    int ret = 0;
    
    while(x != 0){
        if(x & 1) ++ret;
        x >>= 1;
    }
    
    return ret;
}

int mask,adj[30][30];
bool visited[30];

bool dfs(int v){
    if(v == 1) return true;
    
    if(visited[v]) return false;
    visited[v] = true;
    
    int ret = false;
    
    for(int i = 0;i < 30 && !ret;++i)
        if(adj[v][i] & mask)
            ret = (ret || dfs(i));
    
    return ret;
}

int main(){
    int K,N,M;
    
    scanf("%d %d %d",&K,&N,&M);
    
    memset(adj,0,sizeof(adj));
    
    for(int i = 0,u,v,t;i < M;++i){
        scanf("%d %d %d",&u,&v,&t);
        
        adj[u][v] |= (1 << t);
        adj[v][u] |= (1 << t);
    }
    
    int ans = K,types = (1 << K) - 1;
    
    for(mask = 0;mask < (1 << K);++mask){
        if(bitCount(mask) < ans){
            memset(visited,false,sizeof(visited));
            
            if(dfs(0)){
                ans = bitCount(mask);
                types = mask;
            }
        }
    }
    
    printf("%d\n",ans);
    
    for(int i = 0;i < K;++i)
        if(types & (1 << i))
            printf("%d ",i);
    
    printf("\n");
    
    return 0;
}
