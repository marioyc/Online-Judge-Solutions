#include <cstdio>

using namespace std;

#define MAX_SIZE 10000
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
    int N,M,K;
    
    while(scanf("%d %d %d",&N,&M,&K)==3){
        for(int i = 0;i<N;++i) Make_Set(i);
        
        for(int i = 0,u,v;i<M;++i){
            scanf("%d %d",&u,&v);
            Union(u,v);
        }
        
        for(int i = 0,u,v;i<K;++i){
            scanf("%d %d",&u,&v);
            if(Find(u)==Find(v)) puts("YES");
            else puts("NO");
        }
    }
    
    return 0;
}
