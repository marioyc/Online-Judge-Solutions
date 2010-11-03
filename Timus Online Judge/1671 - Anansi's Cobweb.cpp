#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_V 100000

int N,M,num_comp;
int parent[MAX_V],rank[MAX_V];

void init(){
    for(int i = 0;i<N;++i){
        parent[i] = i;
        rank[i] = 0;
    }
    
    num_comp = N;
}

int Find(int v){
    if(parent[v]==v) return v;
    parent[v] = Find(parent[v]);
    return parent[v];
}

void Union(int u, int v){
    int PU = Find(u), PV = Find(v);
    if(PU==PV) return;
    --num_comp;
    
    if(rank[PU]<rank[PV]) parent[PU] = PV;
    else{
        parent[PV] = PU;
        if(rank[PU]==rank[PV]) ++rank[PU];
    }
}

#define MAX_E 100000

int Eu[MAX_E],Ev[MAX_E];
int Q,ind[MAX_E],ans[MAX_E];
bool add[MAX_E];

int main(){
    scanf("%d %d",&N,&M);
    
    for(int i = 0;i<M;++i)
        scanf("%d %d",&Eu[i],&Ev[i]);
    
    scanf("%d",&Q);
    memset(add,true,sizeof(add));
    
    for(int i = 0;i<Q;++i){
        scanf("%d",&ind[i]);
        add[--ind[i]] = false;
    }
    
    init();
    
    for(int i = 0;i<M;++i){
        if(!add[i]) continue;
        Union(Eu[i],Ev[i]);
    }
    
    for(int i = Q-1;i>=0;--i){
        ans[i] = num_comp;
        Union(Eu[ind[i]],Ev[ind[i]]);
    }
    
    printf("%d",ans[0]);
    for(int i = 1;i<Q;++i) printf(" %d",ans[i]);
    printf("\n");
    
    return 0;
}
