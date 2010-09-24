#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector< vector<int> > G;
int V,ET;
bool *p;

bool canReachWithout(int x){
    if(x==0) return false;
    
    memset(p,false,sizeof(bool)*V);
    
    queue<int> Q;
    Q.push(0);
    int aux;
    *p = true;
    
    while(!Q.empty()){
        aux = Q.front();
        Q.pop();
        
        if(aux==ET) return true;
        
        for(int j=G[aux].size()-1;j>=0;--j){
            if(*(p+G[aux][j]) || G[aux][j]==x) continue;
            *(p+G[aux][j]) = true;
            Q.push(G[aux][j]);
        }
    }
    
    return false;
}

int main(){
    vector< vector<int> > GT;
    vector<int> L;
    int u,v;
    
    scanf("%d %d",&V,&ET);
    
    G.resize(V);
    GT.resize(V);
    
    while(scanf("%d %d",&u,&v)==2){
        G[u].push_back(v);
        GT[v].push_back(u);
    }
    
    bool visited[V];
    memset(visited,false,sizeof(visited));
    
    queue<int> Q;
    Q.push(ET);
    visited[ET] = true;
    
    int aux;
    
    while(!Q.empty()){
        aux = Q.front();
        Q.pop();
        
        if(aux==0) continue;
        
        for(int j=GT[aux].size()-1;j>=0;--j){
            if(visited[GT[aux][j]]) continue;
            visited[GT[aux][j]] = true;
            Q.push(GT[aux][j]);
            L.push_back(GT[aux][j]);
        }
    }
    
    int n = L.size();
    
    p = visited;
    
    for(int i=0;i<n;++i){
        if(!canReachWithout(L[i])){
            printf("Put guards in room %d.\n",L[i]);
            break;
        }
    }
    
    return 0;
}
