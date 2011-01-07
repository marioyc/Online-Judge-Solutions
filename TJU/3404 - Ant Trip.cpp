#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_SIZE 100000

int deg[MAX_SIZE],odds[MAX_SIZE],sz[MAX_SIZE];

int parent[MAX_SIZE],rank[MAX_SIZE];

void Make_Set(const int x){
    parent[x] = x; rank[x] = 0;
}

int Find(const int x){
    if(parent[x]!=x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(const int x, const int y){
    int PX = Find(x),PY = Find(y);
    
    if(rank[PX]>rank[PY]) parent[PY] = PX;
    else{
        parent[PX] = PY;
        if(rank[PX]==rank[PY]) ++rank[PY];
    }
}

int main(){
    int N,M,u,v;   
    
    while(scanf("%d %d",&N,&M)==2){
        memset(deg,0,sizeof(deg));
        
        for(int i = 0;i<N;++i) Make_Set(i);
        
        for(int i = 0;i<M;++i){
            scanf("%d %d",&u,&v);
            --u; --v;
            deg[u] ^= 1; deg[v] ^= 1;
            Union(u,v);
        }
        
        memset(odds,0,sizeof(odds));
        memset(sz,0,sizeof(sz));
        
        for(int i = 0,comp;i<N;++i){
            comp = Find(i);
            ++sz[comp];
            
            if(deg[i]) ++odds[comp];
        }
        
        int ans = 0;
        
        for(int i = 0;i<N;++i){
            if(sz[i]>1){
                if(odds[i]<=2) ++ans;
                else ans += odds[i]>>1;
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
