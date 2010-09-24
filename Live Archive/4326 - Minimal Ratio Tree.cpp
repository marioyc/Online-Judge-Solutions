#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct tree{
    vector<int> L;
    int W_nodes,W_edges;
    
    tree(){
    }
    
    tree(const vector<int> &_L, const int &_W_nodes, const int &_W_edges){
        L=_L; W_nodes=_W_nodes; W_edges=_W_edges;
    }
    
    bool operator < (const tree &X) const{
        int aux=X.W_nodes*W_edges-W_nodes*X.W_edges;
        if(aux!=0) return aux<0;
        return L<X.L;
    }
}a[(1<<15)];

struct edge{
    int u,v,cost;
    
    edge(){
    }
    
    edge(const int _u, const int _v, const int _cost){
        u=_u; v=_v; cost=_cost;
    }
    
    bool operator < (const edge &X) const{
        return cost<X.cost;
    }
};

int parent[15],rank[15];

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

int num_bits(const int x){
    int cont=0;
    for(int i=0;i<31;i++) if(x & (1<<i)) cont++;
    return cont;
}

int main(){
    int n,m,W[15],M[15][15],e,cont,W_nodes,W_edges;
    vector<int> L;
    edge E[105];
    
    while(1){
        scanf("%d %d",&n,&m);
        if(n==0) break;
        
        for(int i=0;i<n;i++) scanf("%d",&W[i]);
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&M[i][j]);
        
        e=0;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                E[e].u=i;
                E[e].v=j;
                E[e].cost=M[i][j];
                e++;
            }
        }
        
        sort(E,E+e);
        cont=0;
        L.resize(m);
        
        for(int mask=0;mask<(1<<n);mask++){
            if(num_bits(mask)==m){
                W_nodes=0;
                
                for(int i=0,j=0;i<n;i++){
                    if(mask & (1<<i)){
                        L[j++]=i+1;
                        W_nodes+=W[i];
                    }
                }
                
                for(int i=0;i<n;i++) if(mask & (1<<i)) Make_Set(i);
                
                W_edges=0;
                
                for(int i=0;i<e;i++){
                    if((mask & (1<<E[i].u)) && (mask & (1<<E[i].v)) && Find(E[i].u)!=Find(E[i].v)){
                        Union(E[i].u,E[i].v);
                        W_edges+=E[i].cost;
                    }
                }
                
                a[cont++]=tree(L,W_nodes,W_edges);
            }
        }
        
        sort(a,a+cont);
        
        for(int i=0;i<m;i++){
            printf("%d",a[0].L[i]);
            if(i<m-1) printf(" ");
            else printf("\n");
        }
    }
    
    return 0;
}
