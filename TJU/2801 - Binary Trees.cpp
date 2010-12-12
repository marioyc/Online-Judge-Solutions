#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

char post[1000];
int adj[1000][2],g[1000];

void dfs(int v){
    
    if(g[v]==0){
        putchar(post[v]);
        return;
    }
    
    dfs(adj[v][0]);
    putchar(post[v]);
    dfs(adj[v][1]);
}

int main(){
    int T,V;
    stack<int> S;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%s",post);
        V = strlen(post);
        memset(g,0,sizeof(g));
        
        for(int i = 0;i<V;++i){
            if(post[i]>='a' && post[i]<='z'){
                S.push(i);
            }else{
                int r = S.top(); S.pop();
                int l = S.top(); S.pop();
                
                g[i] = 2;
                adj[i][0] = l;
                adj[i][1] = r;
                
                S.push(i);
            }
        }
        
        dfs(V-1);
        putchar('\n');
    }
    
    return 0;
}
