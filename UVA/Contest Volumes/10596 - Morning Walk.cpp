#include <cstdio>
#include <cstring>

using namespace std;

int parent[201],rank[201],deg[201];

void Make_Set(int x){
    parent[x] = x;
    rank[x] = 0;
}

int Find(int x){
    if(parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    int PX = Find(x),PY = Find(y);
    
    if(PX == PY) return;
    
    if(rank[PX] < rank[PY]) parent[PX] = PY;
    else{
        if(rank[PX] == rank[PY]) ++rank[PX];
        parent[PY] = PX;
    }
}

int main(){
    int V,E;
    
    while(scanf("%d %d",&V,&E) == 2){
        for(int i = 0;i < V;++i) Make_Set(i);
        
        memset(deg,0,sizeof(deg));
        
        for(int i = 0,u,v;i < E;++i){
            scanf("%d %d",&u,&v);
            ++deg[u]; ++deg[v];
            Union(u,v);
        }
        
        bool ok = true,found = false;
        
        for(int i = 0;i < V;++i) if(deg[i] & 1) ok = false;
        
        for(int i = 0;i < V;++i){
            if(parent[i] == i){
                if(found) ok = false;
                else found = true;
            }
        }
        
        if(!ok) puts("Not Possible");
        else puts("Possible");
    }
    
    return 0;
}
