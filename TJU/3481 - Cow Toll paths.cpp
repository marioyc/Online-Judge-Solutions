#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int N,M,Q;
    scanf("%d %d %d",&N,&M,&Q);
    
    int vcost[N];
    
    for(int i = 0;i<N;++i)
        scanf("%d",&vcost[i]);
    
    int u,v,w,dist[N][N];
    memset(dist,-1,sizeof(dist));
    
    for(int i = 0;i<N;++i)
        dist[i][i] = 0;
    
    for(int i = 0;i<M;++i){
        scanf("%d %d %d",&u,&v,&w);
        --u; --v;
        if(dist[u][v]==-1 || w<dist[u][v])
            dist[u][v] = dist[v][u] = w;
    }
    
    int cost[N][N];
    memset(cost,-1,sizeof(cost));
    
    for(int i = 0;i<N;++i) for(int j = 0;j<N;++j){
        if(dist[i][j]!=-1){
            w = max(vcost[i],vcost[j]);
            cost[i][j] = dist[i][j]+w;
        }
    }
    
    pair<int, int> vaux[N];
    
    for(int i = 0;i<N;++i)
        vaux[i] = make_pair(vcost[i],i);
    sort(vaux,vaux+N);
    
    for(int k = 0;k<N;++k){
        v = vaux[k].second;
        w = vaux[k].first;
        
        for(int i = 0;i<N;++i) for(int j = 0;j<N;++j){
            if(dist[i][v]!=-1 && dist[v][j]!=-1 && (dist[i][j]==-1 || dist[i][v]+dist[v][j]<dist[i][j])){
                dist[i][j] = dist[i][v]+dist[v][j];
                int w2 = max(w,max(vcost[i],vcost[j]));
                
                if(cost[i][j]==-1 || dist[i][j]+w2<cost[i][j])
                    cost[i][j] = dist[i][j]+w2;
            }
        }
    }
    
    for(int i = 0;i<Q;++i){
        scanf("%d %d",&u,&v);
        --u; --v;
        printf("%d\n",cost[u][v]);
    }
    
    return 0;
}
