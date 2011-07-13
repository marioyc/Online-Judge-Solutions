#include <cstdio>
#include <algorithm>

using namespace std;

struct edge{
    int u,v,w;
    
    edge(){}
    
    bool operator < (edge X)const{
        return w < X.w;
    }
}L[124750];

int parent[500],rank[500];

void init(int N){
    for(int i = 0;i < N;++i){
        parent[i] = i;
        rank[i] = 0;
    }
}

int Find(int x){
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int x, int y){
    int PX = Find(x),PY = Find(y);
    
    if(rank[PX] < rank[PY]) parent[PY] = PX;
    else{
        parent[PX] = PY;
        if(rank[PX] == rank[PY]) ++rank[PY];
    }
}

int main(){
    int T,N,E,w;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        E = 0;
        
        for(int i = 0;i < N;++i){
            for(int j = 0;j < N;++j){
                scanf("%d",&w);
                
                if(i < j){
                    L[E].u = i;
                    L[E].v = j;
                    L[E].w = w;
                    ++E;
                }
            }
        }
        
        init(N);
        sort(L,L + E);
        
        int ans = 0;
        
        for(int i = 0;i < E;++i){
            if(Find(L[i].u) != Find(L[i].v)){
                Union(L[i].u,L[i].v);
                ans = max(ans,L[i].w);
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
