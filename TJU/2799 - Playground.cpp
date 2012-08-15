#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

bool visited[400];
vector<int> L[400];
int cont1,cont2;

void dfs(int cur, int c){
    ++cont1;
    if(c) ++cont2;
    
    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i];
        
        if(!visited[to]){
            visited[to] = true;
            dfs(to,c ^ 1);
        }
    }
}

int main(){
    int T,n;
    int M[200][200];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&n);
        
        for(int i = 0;i < 2 * n;++i)
            L[i].clear();
        
        for(int i = 0;i < n;++i){
            for(int j = 0;j < n;++j){
                scanf("%d",&M[i][j]);
                
                if(M[i][j] == 1){
                    L[i].push_back(n + j);
                    L[n + j].push_back(i);
                }
            }
        }
        
        memset(visited,false,sizeof visited);
        int ans = 0;
        
        for(int i = 0;i < 2 * n;++i){
            if(!visited[i]){
                cont1 = cont2 = 0;
                
                visited[i] = true;
                dfs(i,0);
                
                ans += min(cont2,cont1 - cont2);
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
