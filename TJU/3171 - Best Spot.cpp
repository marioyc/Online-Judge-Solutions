#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int V,F,E;
    scanf("%d %d %d",&V,&F,&E);
    
    int f[F];
    
    for(int i = 0;i<F;++i){
        scanf("%d",&f[i]);
        --f[i];
    }
    
    int dist[V][V];
    memset(dist,-1,sizeof(dist));
    
    for(int i = 0;i<V;++i) dist[i][i] = 0;
    
    for(int i = 0,u,v,w;i<E;++i){
        scanf("%d %d %d",&u,&v,&w);
        --u; --v;
        dist[u][v] = dist[v][u] = w;
    }
    
    for(int k = 0;k<V;++k){
        for(int i = 0;i<V;++i){
            if(dist[i][k]!=-1){
                for(int j = 0;j<V;++j){
                    if(dist[k][j]!=-1){
                        if(dist[i][j]==-1 || dist[i][k]+dist[k][j]<dist[i][j])
                            dist[i][j] = dist[i][k]+dist[k][j];
                    }
                }
            }
        }
    }
    
    int ans = -1,best,tmp;
    
    for(int i = 0;i<V;++i){
        tmp = 0;
        
        for(int j = 0;j<F;++j)
            tmp += dist[i][f[j]];
        
        if(ans==-1 || tmp<best){
            ans = i;
            best = tmp;
        }
    }
    
    printf("%d\n",ans+1);
    
    return 0;
}
