#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> L[1000];
int next_x[1000],x[1000],y[1000];

void dfs(int cur, int prev, int lvl){
    x[cur] = next_x[lvl];
    y[cur] = 2 * lvl - 1000;
    next_x[lvl] += 2;
    
    for(int i = L[cur].size() - 1;i >= 0;--i){
        int nxt = L[cur][i];
        if(nxt == prev) continue;
        
        dfs(nxt,cur,lvl+1);
    }
}

int main(){
    int N;
    scanf("%d",&N);
    
    for(int i = 1,u,v;i < N;++i){
        scanf("%d %d",&u,&v);
        --u; --v;
        
        L[u].push_back(v);
        L[v].push_back(u);
    }
    
    for(int i = 0;i < 1000;++i) next_x[i] = -1000;
    
    dfs(0,-1,0);
    
    for(int i = 0;i < N;++i)
        printf("%d %d\n",x[i],y[i]);
    
    return 0;
}
