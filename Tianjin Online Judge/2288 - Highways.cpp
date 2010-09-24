#include <cstdio>
#include <algorithm>

using namespace std;

int dist2(int x1, int y1, int x2, int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int x[750],y[750]; 

struct edge{
    int u,v,d;
    
    edge(){
    }
    
    edge(int _u, int _v){
        u=_u;
        v=_v;
        d=dist2(x[u],y[u],x[v],y[v]);
    }
    
    bool operator < (edge X) const{
        return d<X.d;
    }
};

int parent[750],rank[750],cont;

void Make_Set(int x){
    parent[x]=x;
    rank[x]=0;
}

int Find(int x){
    if(parent[x]!=x) parent[x]=Find(parent[x]);
    return parent[x];
}

bool print;

void Union(int &x, int &y){
    int PX=Find(x),PY=Find(y);
    if(PX==PY) return;
    
    if(print) printf("%d %d\n",x+1,y+1);
    cont--;
    
    if(rank[PX]>rank[PY]) parent[PY]=PX;
    else{
        parent[PX]=PY;
        if(rank[PX]==rank[PY]) rank[PY]++;
    }
}

void Solve(){
    int N;
    scanf("%d",&N);
    
    for(int i=0;i<N;i++) scanf("%d %d",&x[i],&y[i]);
    
    int E,u,v;
    bool M[N][N];
    for(int i=0;i<N;i++) fill(M[i],M[i]+N,false);
    for(int i=0;i<N;i++) Make_Set(i);
    
    scanf("%d",&E);
    
    cont=N; print=false;
    for(int i=0;i<E;i++){
        scanf("%d %d",&u,&v);
        u--; v--;
        M[u][v]=M[v][u]=true;
        Union(u,v);
    }
    
    edge a[N*(N-1)/2];
    E=0;
    
    for(int i=0;i<N;i++)
        for(int j=i+1;j<N;j++)
            if(!M[i][j])
                a[E++]=edge(i,j);
    
    sort(a,a+E);
    print=true;
    
    for(int i=0;cont>1;i++)
        Union(a[i].u,a[i].v);
}

int main(){
    Solve();
    
    return 0;
}
