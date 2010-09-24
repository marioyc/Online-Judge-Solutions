#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_SIZE 50

int parent[MAX_SIZE],rank[MAX_SIZE],comp;

void Make_Set(const int x){
    parent[x]=x;
    rank[x]=0;
}

int Find(const int x){
    if(parent[x]!=x) parent[x]=Find(parent[x]);
    return parent[x];
}

void Union(const int x, const int y){
    int PX=Find(x),PY=Find(y);
    
    if(rank[PX]>rank[PY]) parent[PY]=PX;
    else{
        parent[PX]=PY;
        if(rank[PX]==rank[PY]) rank[PY]++;
    }
}

struct edge{
    int u,v,L;
    
    edge(){
    }
    
    edge(const int _u, const int _v, const int _L){
        u=_u; v=_v; L=_L;
    }
    
    bool operator < (const edge &X) const{
        return L<X.L;
    }
}e[1225];


int main(){
    int N,E,M[50][50],u,v,L,sz,ans;
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        
        scanf("%d",&E);
        
        for(int i=0;i<N;i++) fill(M[i],M[i]+N,-1);
        
        for(int i=0;i<E;i++){
            scanf("%d %d %d",&u,&v,&L);
            u--; v--;
            
            if(M[u][v]==-1) M[u][v]=M[v][u]=L;
            else M[u][v]=M[v][u]=min(M[u][v],L);
        }
        
        E=0;
        
        for(int i=0;i<N;i++)
            for(int j=i+1;j<N;j++)
                if(M[i][j]!=-1)
                    e[E++]=edge(i,j,M[i][j]);
        
        sort(e,e+E);
        
        comp=N;
        for(int i=0;i<N;i++) Make_Set(i);
        
        ans=0;
        
        for(int i=0;i<E && comp!=1;i++){
            if(Find(e[i].u)!=Find(e[i].v)){
                Union(e[i].u,e[i].v);
                ans+=e[i].L;
                comp--;
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
