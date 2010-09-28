#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int parent[26],rank[26];

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
    
    if(rank[PX]>rank[PY]) parent[PY]=PX;
    else{
        parent[PX]=PY;
        if(rank[PX]==rank[PY]) rank[PY]++;
    }
}

struct edge{
    int u,v,d;
    
    edge(int _u, int _v, int _d){
        u=_u;
        v=_v;
        d=_d;
    }
    
    bool operator < (edge X) const{
        if(d!=X.d) return d<X.d;
        if(u!=X.u) return u<X.u;
        return v<X.v;
    }
};

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int T,V,d,u,v;
    vector<edge> L;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d",&V);
        
        L.clear();
        
        for(int i=0;i<V;i++){
            scanf("%d",&d);
            
            for(int j=1;j<V;j++){
                scanf(",%d",&d);
                if(d!=0 && j>i) L.push_back(edge(i,j,d));
            }
        }
        
        sort(L.rbegin(),L.rend());
        
        for(int i=0;i<V;i++) Make_Set(i);
        
        printf("Case %d:\n",tc);
        
        for(int i=L.size()-1;i>=0;i--){
            u=L[i].u;
            v=L[i].v;
            
            if(Find(u)!=Find(v)){
                Union(u,v);
                printf("%c-%c %d\n",'A'+u,'A'+v,L[i].d);
            }
        }
    }
    
    return 0;
}
