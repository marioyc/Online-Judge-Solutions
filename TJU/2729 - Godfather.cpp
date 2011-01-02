#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define MAX_SIZE 50000

vector<int> L[MAX_SIZE];
bool visited[MAX_SIZE];
int V,ans[MAX_SIZE],down[MAX_SIZE];

void DFS(int cur){
    visited[cur] = true;
    down[cur] = 1;
    ans[cur] = 0;
    
    for(int i = L[cur].size()-1;i>=0;--i){
        int nxt = L[cur][i];
        
        if(!visited[nxt]){
            DFS(nxt);
            down[cur] += down[nxt];
            if(down[nxt]>ans[cur]) ans[cur] = down[nxt];
        }
    }
    
    if(V-down[cur]>ans[cur]) ans[cur] = V-down[cur];
}

int main(){
    scanf("%d",&V);
    
    for(int i = 1,u,v;i<V;++i){
        scanf("%d %d",&u,&v);
        --u; --v;
        L[u].push_back(v);
        L[v].push_back(u);
    }
    
    memset(visited,false,sizeof(visited));
    DFS(0);
    
    int best = V;
    for(int i = 0;i<V;++i) if(ans[i]<best) best = ans[i];
    
    for(int i = 0,first = 1;i<V;++i){
        if(ans[i]==best){
            if(first==0) putchar(' ');
            first = 0;
            printf("%d",i+1);
        }
    }
    
    putchar('\n');
    
    return 0;
}
