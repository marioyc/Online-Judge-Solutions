#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> L[200];
int l[200],r[200];
bool visited[200];

bool dfs(int cur){
    if(visited[cur]) return false;
    visited[cur] = true;
    
    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i];
        
        if(l[to] == -1 || dfs(l[to])){
            r[cur] = to;
            l[to] = cur;
            return true;
        }
    }
    
    return false;
}

bool matching(int V){
    memset(l,-1,sizeof l);
    memset(r,-1,sizeof r);
    bool found = true;
    
    while(found){
        memset(visited,false,sizeof visited);
        found = false;
        
        for(int i = 0;i < V;++i)
            if(r[i] == -1)
                found |= dfs(i);
    }
    
    int cont = 0;
    
    for(int i = 0;i < V;++i)
        if(r[i] != -1) ++cont;
    
    return cont == V; 
}

int main(){
    int N;
    char M[200][201];
    
    while(scanf("%d",&N) == 1){
        for(int i = 0;i < N;++i)
            scanf("%s",M[i]);
        
        for(int i = 0;i < N;++i)
            L[i].clear();
        
        for(int i = 0;i < N;++i)
            for(int j = 0;j < N;++j)
                if(M[i][j] == 'U')
                    L[i].push_back(j);
        
        puts(matching(N)? "YES" : "NO");
    }
    
    return 0;
}
