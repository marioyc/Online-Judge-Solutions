#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int parent[1000],rank[1000],cont;

void Make_Set(int x){
    parent[x]=x;
    rank[x]=0;
}

int Find(int x){
    if(parent[x]!=x) parent[x]=Find(parent[x]);
    return parent[x];
}

void Union(int &x, int &y){
    int PX=Find(x),PY=Find(y);
    if(PX==PY) return;
    cont--;
    
    if(rank[PX]>rank[PY]) parent[PY]=PX;
    else{
        parent[PX]=PY;
        if(rank[PX]==rank[PY]) rank[PY]++;
    }
}

struct road{
    int u,v,c;
    
    road(){
    }
    
    road(int _u, int _v, int _c){
        u=_u;
        v=_v;
        c=_c;
    }
    
    bool operator < (road X) const{
        return c<X.c;
    }
};

int main(){
    int T,N,M,K,u,v,c,ans;
    scanf("%d",&T);
    
    vector<road> L;
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d %d %d",&N,&M,&K);
        
        for(int i=0;i<N;i++) Make_Set(i);
        cont=N;
        
        for(int i=0;i<M;i++){
            scanf("%d %d",&u,&v);
            u--; v--;
            Union(u,v);
        }
        
        L.clear();
        
        for(int i=0;i<K;i++){
            scanf("%d %d %d",&u,&v,&c);
            u--; v--;
            L.push_back(road(u,v,c));
        }
        
        sort(L.begin(),L.end());
        
        ans=0;
        
        for(int i=0;i<K;i++){
            if(Find(L[i].u)!=Find(L[i].v)){
                ans+=L[i].c;
                Union(L[i].u,L[i].v);
            }
        }
        
        if(cont==1) printf("%d\n",ans);
        else printf("-1\n");
    }
    
    return 0;
}
