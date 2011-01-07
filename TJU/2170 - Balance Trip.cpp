#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct edge{
    int u,v,w;
    
    edge(){}
    
    bool operator < (edge X)const{
        return w<X.w;
    }
}E[1000];

#define MAX_SIZE 200
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

int N,M,S,T;

int solve2(int min_w){
    for(int i = 0;i<N;++i) Make_Set(i);
    
    for(int i = 0;i<M;++i){
        if(E[i].w>=min_w){
            Union(E[i].u,E[i].v);
            if(Find(S)==Find(T)) return E[i].w;
        }
    }
    
    return -1;
}

int solve(){
    int ret = -1;
    
    for(int i = 0,x;i<M;++i){
        x = solve2(E[i].w);
        if(x!=-1){
            if(ret==-1) ret = x-E[i].w;
            else ret = min(ret,x-E[i].w);
        }
    }
    
    return ret;
}

int main(){
    while(true){
        scanf("%d %d",&N,&M);
        if(N==0 || M==0) break;
        
        for(int i = 0,u,v,w;i<M;++i){
            scanf("%d %d %d",&E[i].u,&E[i].v,&E[i].w);
            --E[i].u; --E[i].v;
        }
        
        sort(E,E+M);
        
        scanf("%d %d",&S,&T);
        --S; --T;
        
        printf("%d\n",solve());
    }
    
    return 0;
}
