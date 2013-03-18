#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define MAXW 100000

map<int, int> id;
int cont;
vector<int> L[2 * MAXW];
bool visited[2 * MAXW],done[2 * MAXW];
int h[2 * MAXW],cycle;

void dfs(int cur, int prev, int curh){
    if(visited[cur]) return;
    visited[cur] = true;
    h[cur] = curh;
    
    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i];
        
        if(!visited[to]) dfs(to,cur,curh + 1);
        else if(to != prev && !done[to]) cycle = curh - h[to] + 1;
    }
    
    done[cur] = true;
}

int main(){
    int K,W;
    
    while(true){
        scanf("%d %d",&K,&W);
        if(K == 0) break;
        
        for(int i = 0;i < cont;++i)
            L[i].clear();
        
        id.clear();
        cont = 0;
        
        for(int i = 0,u,v;i < W;++i){
            scanf("%d %d",&u,&v);
            
            if(id.find(u) == id.end()) id[u] = cont++;
            if(id.find(v) == id.end()) id[v] = cont++;
            
            u = id[u]; v = id[v];
            L[u].push_back(v);
            L[v].push_back(u);
        }
        
        bool ok = true;
        
        for(int i = 0;i < cont;++i){
            sort(L[i].begin(),L[i].end());
            L[i].erase(unique(L[i].begin(),L[i].end()),L[i].end());
        }
        
        for(int i = 0;i < cont;++i)
            if(L[i].size() > 2)
                ok = false;
        
        if(!ok){
            puts("N");
            continue;
        }
        
        memset(visited,false,sizeof visited);
        memset(done,false,sizeof visited);
        cycle = -1;
        
        for(int i = 0;i < cont;++i)
            if(!visited[i])
                dfs(i,-1,0);
        
        if(cycle == -1 || cycle == K) puts("Y");
        else puts("N");
    }
    
    return 0;
}
