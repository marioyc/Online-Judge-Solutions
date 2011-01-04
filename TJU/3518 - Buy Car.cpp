#include <cstdio>
#include <algorithm>

using namespace std;

struct edge{
    int u,v,w;
    
    edge(){}
    
    bool operator < (edge X)const{
        return w<X.w;
    }
}E[19900];

#define MAX_SIZE 200
int N,M,parent[MAX_SIZE],rank[MAX_SIZE],comp;

void Make_Set(const int x){
    parent[x] = x; rank[x] = 0;
}

int Find(const int x){
    if(parent[x]!=x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(const int x, const int y){
    int PX = Find(x),PY = Find(y);
    if(PX==PY) return;
    --comp;
    
    if(rank[PX]>rank[PY]) parent[PY] = PX;
    else{
        parent[PX] = PY;
        if(rank[PX]==rank[PY]) ++rank[PY];
    }
}

bool check(int max_cap){
    for(int i = 0;i<N;++i) Make_Set(i);
    comp = N;
    
    for(int i = 0;i<M && E[i].w<=max_cap;++i)
        Union(E[i].u,E[i].v);
    
    return (comp==1);
}

int main(){
    int T;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&N,&M);
        
        for(int i = 0;i<M;++i){
            scanf("%d %d %d",&E[i].u,&E[i].v,&E[i].w);
            --E[i].u; --E[i].v;
            E[i].w = (E[i].w+9)/10;
        }
        
        sort(E,E+M);
        
        if(!check(100)) puts("-1");
        else{
            int lo = 1,hi = 100,mi;
            
            while(lo<hi){
                mi = (lo+hi)>>1;
                
                if(!check(mi)) lo = mi+1;
                else hi = mi;
            }
            
            printf("%d\n",hi);
        }
    }
    
    return 0;
}
