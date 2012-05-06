#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int N,M,K;
    
    scanf("%d %d %d",&N,&M,&K);
    
    int u[M],v[M],c[M];
    
    for(int i = 0;i < M;++i){
        scanf("%d %d %d",&u[i],&v[i],&c[i]);
        --u[i]; --v[i];
    }
    
    int s[N];
    
    for(int i = 0;i < N;++i)
        scanf("%d",&s[i]);
    
    int dist[N];
    bool can[N];
    
    memset(can,false,sizeof can);
    dist[0] = K;
    can[0] = true;
    
    for(int it = 0;it < 100000;++it){
        for(int e = 0;e < M;++e){
            if(can[ u[e] ] && dist[ u[e] ] >= c[e]){
                if(!can[ v[e] ]) dist[ v[e] ] = (dist[ u[e] ] - c[e] + s[ v[e] ]) / 2;
                else dist[ v[e] ] = max(dist[ v[e] ],(dist[ u[e] ] - c[e] + s[ v[e] ]) / 2);
                
                can[ v[e] ] = true;
            }
            
            swap(u[e],v[e]);
            
            if(can[ u[e] ] && dist[ u[e] ] >= c[e]){
                if(!can[ v[e] ]) dist[ v[e] ] = (dist[ u[e] ] - c[e] + s[ v[e] ]) / 2;
                else dist[ v[e] ] = max(dist[ v[e] ],(dist[ u[e] ] - c[e] + s[ v[e] ]) / 2);
                
                can[ v[e] ] = true;
            }
        }
    }
    
    printf("%d\n",dist[N - 1]);
    
    return 0;
}
