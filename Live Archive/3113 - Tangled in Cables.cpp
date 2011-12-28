#include <cstdio>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

struct edge{
    int u,v;
    double dist;
    
    edge(){}
    
    bool operator < (edge X)const{
        return dist < X.dist;
    }
}L[50000];

int parent[50000],rank[50000];

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
    int PX = Find(x), PY = Find(y);
    
    if(rank[PX] < rank[PY]) parent[PX] = PY;
    else{
        parent[PY] = PX;
        if(rank[PX] == rank[PY]) ++rank[PX];
    }
}

int main(){
    double total;
    int N,E;
    char name[21],name2[21];
    map<string, int> id;
    
    while(scanf("%lf",&total) == 1){
         scanf("%d",&N);
         
         id.clear();
         
         for(int i = 0;i < N;++i){
            scanf("%s",name);
            id[name] = i;
         }
         
         scanf("%d",&E);
         
         for(int i = 0;i < E;++i){
            scanf("%s %s",name,name2);
            
            L[i].u = id[name];
            L[i].v = id[name2];
            
            scanf("%lf",&L[i].dist);
         }
         
         sort(L,L + E);
         init(N);
         
         double need = 0;
         
         for(int i = 0;i < E;++i){
            if(Find(L[i].u) != Find(L[i].v)){
                Union(L[i].u,L[i].v);
                need += L[i].dist;
            }
         }
         
         if(total < need) puts("Not enough cable");
         else printf("Need %.1f miles of cable\n",need);
    }
    
    return 0;
}
