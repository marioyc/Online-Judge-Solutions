#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int V,l[40000],r[40000];
vector<int> L[40000];
bool visited[40000];

bool dfs(int pos){
    if(visited[pos]) return 0;
    visited[pos] = 1;
    
    for(int i = L[pos].size() - 1,to;i >= 0;--i){
        to = L[pos][i];
        
        if(l[to] == -1 || dfs(l[to])){
            r[pos] = to;
            l[to] = pos;
            return 1;
        }
    }
    
    return 0;
}

int main(){
    int n,m,cont = 0;
    int ro[40000],c[40000];
    
    scanf("%d %d",&n,&m);
    
    for(int i = 0,x;i < n;++i){
        for(int j = 0;j < m;++j){
            scanf("%d",&x);
            
            if(x == 1){
                L[i].push_back(j);
            }
        }
    }
    
    V = n;
    
    memset(l,-1,sizeof l);
    memset(r,-1,sizeof r);
    
    bool change = true;
    
    while(change){
        memset(visited,false,sizeof visited);
        change = 0;
        
        for(int i = 0;i < V;++i)
            if(r[i] == -1)
                change |= dfs(i);
    }
    
    int ans = 0;
    
    for(int i = 0;i < V;++i)
        if(r[i] != -1) ++ans;
    
    printf("%d\n",ans);
    
    return 0;
}
