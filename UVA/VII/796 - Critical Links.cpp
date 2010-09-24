#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define SZ 100

bool M[SZ][SZ];
int N,colour[SZ],dfsNum[SZ],num,pos[SZ],leastAncestor[SZ],parent[SZ];

void dfs(int u){
    int v;
    
    stack<int> S;
    S.push(u);
    
    while(!S.empty()){
        v=S.top();
        if(colour[v]==0){
            colour[v]=1;
            dfsNum[v]=num++;
            leastAncestor[v]=num;
        }
        
        for(;pos[v]<N;pos[v]++){
            if(M[v][pos[v]] && pos[v]!=parent[v]){
                if(colour[pos[v]]==0){
                    parent[pos[v]]=v;
                    S.push(pos[v]);
                    break;
                }else leastAncestor[v]<?=dfsNum[pos[v]];
            }
        }
        
        if(pos[v]==N){
            colour[v]=2;
            S.pop();
            
            if(v!=u) leastAncestor[parent[v]]<?=leastAncestor[v];
        }
    }
}

struct edge{
    int u,v;
    
    edge(){
    }
    
    edge(const int _u, const int _v){
        u=min(_u,_v);
        v=max(_u,_v);
    }
    
    bool operator < (const edge &X) const{
        if(u!=X.u) return u<X.u;
        return v<X.v;
    }
};

vector<edge> v;

void Bridge_detection(){
    memset(colour,0,sizeof(colour));
    memset(pos,0,sizeof(pos));
    memset(parent,-1,sizeof(parent));
    num=0;
    
    int ans=0;
    
    for(int i=0;i<N;i++) if(colour[i]==0) dfs(i);
    
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(parent[j]==i && leastAncestor[j]>dfsNum[i]) ans++;
    
    printf("%d critical links\n",ans);
    
    v.clear();
    
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(parent[j]==i && leastAncestor[j]>dfsNum[i]) v.push_back(edge(i,j));
    
    sort(v.rbegin(),v.rend());
    
    for(int i=v.size()-1;i>=0;i--) printf("%d - %d\n",v[i].u,v[i].v);
    
    printf("\n");
}

int main(){
    int u,v,e;
    char c;
    
    while(scanf("%d\n",&N)==1){
        memset(M,false,sizeof(M));
        
        for(int i=0;i<N;i++){
            scanf("%d",&u);
            
            scanf("%c%c%d%c",&c,&c,&e,&c);
            
            for(int j=0;j<e;j++){
                scanf(" %d",&v);
                M[u][v]=M[v][u]=true;
            }
        }
        Bridge_detection();
    }
    
    return 0;
}
