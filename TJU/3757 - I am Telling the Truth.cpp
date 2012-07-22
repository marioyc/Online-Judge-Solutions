#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

vector<int> L[60];
int l[3600],r[60];
bool visited[60];

bool dfs(int x){
    if(visited[x]) return 0;
    visited[x] = true;
    
    for(int i = L[x].size() - 1,to;i >= 0;--i){
        to = L[x][i];
        
        if(l[to] == -1 || dfs(l[to])){
            l[to] = x;
            r[x] = to;
            return 1;
        }
    }
    
    return 0;
}

int main(){
    int T,n,x[60],y[60],sol[60];
    bool done[60];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&n);
        
        for(int i = 0;i < n;++i){
            scanf("%d %d",&x[i],&y[i]);
            y[i] = min(y[i],x[i] + n - 1);
        }
        
        map<int, int> id;
        int V2 = 0;
        
        for(int i = 0;i < n;++i)
            for(int j = x[i];j <= y[i];++j)
                if(id.find(j) == id.end()) id[j] = V2++;
        
        for(int i = 0;i < n;++i)
            L[i].clear();
        
        for(int i = 0;i < n;++i)
            for(int j = x[i];j <= y[i];++j)
                L[i].push_back(id[j]);
        
        memset(l,-1,sizeof l);
        memset(r,-1,sizeof r);
        int ans = 0;
        
        for(int i = n - 1;i >= 0;--i){
            memset(visited,false,sizeof visited);
            
            if(dfs(i)) ++ans;
        }
        
        printf("%d\n",ans);
        
        for(int i = 0,j = 0;i < n;++i){
            if(r[i] != -1){
                printf("%d",i + 1);
                ++j;
                
                if(j < ans) printf(" ");
            }
        }
        
        printf("\n");
    }
    
    return 0;
}
