#include <cstdio>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

struct edge{
    int u,v,w;
    
    edge(){}
    
    bool operator < (edge X)const{
        return w < X.w;
    }
}L[50000];

int parent[2000],rank[2000];

void init(int V){
    for(int i = 0;i < V;++i){
        parent[i] = i;
        rank[i] = 0;
    }
}

int Find(int v){
    if(parent[v] != v) parent[v] = Find(parent[v]);
    return parent[v];
}

void Union(int u, int v){
    int PU = Find(u),PV = Find(v);
    
    if(rank[PU] > rank[PV]) parent[PV] = PU;
    else{
        parent[PU] = PV;
        if(rank[PU] == rank[PV]) ++rank[PV];
    }
}

int main(){
    int T,V,E;
    char name1[9],name2[9];
    map<string,int> id;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&V,&E);
        
        id.clear();
        
        for(int i = 0,j = 0;i < E;++i){
            scanf("%s %s %d",name1,name2,&L[i].w);
            
            if(id.find(name1) == id.end()) id[name1] = j++;
            if(id.find(name2) == id.end()) id[name2] = j++;
            
            L[i].u = id[name1]; L[i].v = id[name2];
        }
        
        sort(L,L + E);
        init(V);
        
        int ans = 0;
        
        for(int i = 0;i < E;++i){
            if(Find(L[i].u) != Find(L[i].v)){
                Union(L[i].u,L[i].v);
                ans += L[i].w;
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
