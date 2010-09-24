#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 100000

int V;
vector<int> adj[MAXN];
int dfn[MAXN],low[MAXN];
vector< vector<int> > C;
stack< pair<int, int> > stk;

void cache_bc(int x, int y){
    vector<int> com;
    int tx,ty;
    
    do{
        tx = stk.top().first, ty = stk.top().second;
        stk.pop();
        com.push_back(tx), com.push_back(ty);
    }while(tx!=x || ty!=y);
    
    C.push_back(com);
}

void DFS(int cur, int prev, int number){
    dfn[cur] = low[cur] = number;
    
    for(int i = adj[cur].size()-1;i>=0;--i){
        int next = adj[cur][i];
        if(next==prev) continue;
        if(dfn[next]==-1){
            stk.push(make_pair(cur,next));
            DFS(next,cur,number+1);
            low[cur] = min(low[cur], low[next]);
            if(low[next]>=dfn[cur]) cache_bc(cur,next);
        }else low[cur] = min(low[cur],dfn[next]);
    }
}

void biconnected_components(){
    memset(dfn,-1,sizeof(dfn));
    C.clear();
    DFS(0,0,0);
    
    int comp = C.size();
    
    printf("%d\n",comp);
    
    for(int i = 0;i<comp;++i){
        sort(C[i].begin(),C[i].end());
        C[i].erase(unique(C[i].begin(),C[i].end()),C[i].end());
        int m = C[i].size();
        for(int j = 0;j<m;++j) printf("%d ",1+C[i][j]);
        printf("\n");
    }
}

int main(){    
    freopen("biconex.in","r",stdin);
    freopen("biconex.out","w",stdout);    
    
    int E,u,v;
    scanf("%d %d",&V,&E);
    
    while(E--){
        scanf("%d %d",&u,&v);
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    biconnected_components();

    return 0;
}
