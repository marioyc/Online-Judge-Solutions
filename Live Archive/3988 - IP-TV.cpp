#include <cstdio>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

struct edge{
    int u,v,dist;
    
    edge(){}
    
    bool operator < (edge X)const{
        return dist < X.dist;
    }
}L[50000];

int parent[2000],rank[2000];

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
    int T,N,E;
    char name[21],name2[21];
    map<string, int> id;
    bool first = true;
    
    scanf("%d",&T);
    
    while(T--){
         scanf("%d %d",&N,&E);
         id.clear();
         
         for(int i = 0,aux = 0;i < E;++i){
            scanf("%s %s %d",name,name2,&L[i].dist);
            
            if(id.find(name) == id.end()) id[name] = aux++;
            if(id.find(name2) == id.end()) id[name2] = aux++;
            
            L[i].u = id[name];
            L[i].v = id[name2];
         }
         
         sort(L,L + E);
         init(N);
         
         int need = 0;
         
         for(int i = 0;i < E;++i){
            if(Find(L[i].u) != Find(L[i].v)){
                Union(L[i].u,L[i].v);
                need += L[i].dist;
            }
         }
         
         if(!first) printf("\n");
         first = false;
         
         printf("%d\n",need);
    }
    
    return 0;
}
