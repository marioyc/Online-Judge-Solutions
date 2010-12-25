#include <cstdio>
#include <fstream>
#include <algorithm>

using namespace std;

int *parent,*rank;

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

struct edge{
    int u,v,w;
    
    edge(){}
    
    edge(int _u, int _v, int _w){
        u = _u; v = _v; w = _w;
    }
    
    bool operator < (edge X)const{
        return w<X.w;
    }
}*S;

int main(int argc, char** argv){
    freopen(argv[1],"r",stdin);
    
    int V,E;
    scanf("%d %d",&V,&E);
    
    parent = new int[V];
    rank = new int[V];
    S = new edge[E];
    
    for(int i = 0;i<V;++i) Make_Set(i);
    
    for(int i = 0,u,v,w;i<E;++i){
        scanf("%d %d %d",&u,&v,&w);
        S[i] = edge(u,v,w);
    }
    
    sort(S,S+E);
    int ans = 0;
    
    for(int i = 0;i<E;++i){
        if(Find(S[i].u)!=Find(S[i].v)){
            Union(S[i].u,S[i].v);
            ans += S[i].w;
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}
