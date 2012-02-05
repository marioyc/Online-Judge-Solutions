#include <cstdio>

using namespace std;

const int MAXN = 10000;
const int MAXE = 50000;

int parent[MAXN],rank[MAXN];

void init(int V){
    for(int i = 0;i < V;++i){
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
    
    if(PX != PY){
        if(rank[PX] < rank[PY]) parent[PX] = PY;
        else{
            if(rank[PX] == rank[PY]) ++rank[PX];
            parent[PY] = PX;
        }
    }
}

int main(){
    int T,N,E,K;
    int a[MAXE],b[MAXE];
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d %d %d",&N,&E,&K);
        
        for(int i = 0;i < E;++i)
            scanf("%d %d",&a[i],&b[i]);
        
        init(N);
        
        for(int i = 0;i < E;++i){
            if(a[i] >= K && b[i] >= K)
                Union(a[i],b[i]);
        }
        
        int ans = 0;
        
        for(int i = 0;i < E;++i){
            if(a[i] < K || b[i] < K)
                if(Find(a[i]) == Find(b[i])) ++ans;
                else Union(a[i],b[i]);
        }
        
        printf("Case #%d: %d\n",tc,ans);
    }
    
    return 0;
}
