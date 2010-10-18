#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

#define MAX_V1 500
#define MAX_V2 500
#define MAX_E 50000

int V1,V2,l[MAX_V1],r[MAX_V2];
int E,to[MAX_E],next[MAX_E],last[MAX_V1];
bool visited[MAX_V1];

void init(){
    memset(last,-1,sizeof(int)*V1);
    E = 0;
}

void add_edge(int u, int v){
    to[E] = v, next[E] = last[u]; last[u] = E; ++E;
}

bool pairup(int u){
    if(visited[u]) return false;
    visited[u] = true;
    
    for(int e = last[u];e!=-1;e = next[e]){
        int v = to[e];
        
        if(r[v]==-1 || pairup(r[v])){
            l[u] = v;
            r[v] = u;
            return true;
        }
    }
    
    return false;
}

int hopcroft_karp(){
    bool change = true;
    memset(l,-1,sizeof(int)*V1);
    memset(r,-1,sizeof(int)*V2);
    
    while(change){
        change = false;
        memset(visited,false,sizeof(bool)*V1);
        
        for(int i = 0;i<V1;++i)
            if(l[i]==-1) change |= pairup(i);
    }
    
    int ret = 0;
    
    for(int i = 0;i<V1;++i)
        if(l[i]==-1) ++ret;
    
    return ret;
}

int main(){
    freopen("1047.in","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N,u,v,E,color[500];
    vector<int> L[500];
    
    while(scanf("%d",&N)==1){
        for(int i = 0;i<N;++i){
            L[i].clear();
            scanf("%d: (%d)",&u,&E);
            
            for(int e = 0;e<E;++e){
                scanf(" %d",&v);
                L[u].push_back(v);
            }
        }
        
        memset(color,-1,sizeof(color));
        
        V1 = V2 = N;
        init();
        
        for(int i = 0;i<N;++i){
            if(color[i]!=-1) continue;
            
            queue<int> Q;
            Q.push(i);
            color[i] = 0;
            
            while(!Q.empty()){
                int aux = Q.front();
                Q.pop();
                
                for(int j = L[aux].size()-1;j>=0;--j){
                    int v = L[aux][j];
                    
                    if(color[v]==-1){
                        color[v] = 1-color[aux];
                        Q.push(v);
                    }
                }
            }
        }
        
        for(int i = 0;i<N;++i){
            if(color[i]==1) continue;
            for(int e = L[i].size()-1;e>=0;--e){
                int v = L[i][e];
                add_edge(i,v);
            }
        }
        
        printf("%d\n",hopcroft_karp());
    }
    
    return 0;
}
