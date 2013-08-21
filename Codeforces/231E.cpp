#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 100005

vector<int> L[MAXN],L2[MAXN];
bool visited[MAXN],done[MAXN];
int  h[MAXN];
vector<int> path;
int cycle[MAXN],ncycles,cont;

void dfs(int cur, int curh, int prev){
    visited[cur] = true;
    h[cur] = curh;
    path.push_back(cur);
    
    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i];
        
        if(!visited[to]) dfs(to,curh + 1,cur);
        else if(to != prev && !done[to]){
            for(int j = h[to];j <= curh;++j)
                cycle[ path[j] ] = ncycles;
            ++ncycles;
        }
    }
    
    done[cur] = true;
    path.pop_back();
}

int p[MAXN],ans[MAXN];

void dfs2(int cur, int curh){
    visited[cur] = true;
    h[cur] = curh;
    
    if(cur == 0) ans[0] = (cur < ncycles? 1 : 0);
    else ans[cur] = ans[ p[cur] ] + (cur < ncycles? 1 : 0);
    
    for(int i = L2[cur].size() - 1,to;i >= 0;--i){
        to = L2[cur][i];
        
        if(!visited[to]){
            p[to] = cur;
            dfs2(to,curh + 1);
        }
    }
}

int P[17][MAXN];

int lca(int u, int v){
    if(h[u] < h[v]) swap(u,v);
    int diff = h[u] - h[v];
    
    for(int i = 0;i <= 16;++i)
        if(diff >> i & 1)
            u = P[i][u];
    
    for(int i = 16;i >= 0;--i)
        if(P[i][u] != P[i][v])
            u = P[i][u], v = P[i][v];
    
    if(u != v)
        u = P[0][u], v = P[0][v];
    
    return u;
}

#define MOD 1000000007

int mod_pow(long long a, int b){
    long long ret = 1;
    
    while(b){
        if(b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    
    return ret;
}

int main(){
    int n,m;
    
    scanf("%d %d",&n,&m);
    
    for(int i = 0,u,v;i < m;++i){
        scanf("%d %d",&u,&v);
        L[u].push_back(v);
        L[v].push_back(u);
    }
    
    memset(cycle,-1,sizeof cycle);
    dfs(1,0,0);
    cont = ncycles;
    
    for(int i = 1;i <= n;++i)
        if(cycle[i] == -1) cycle[i] = cont++;
    
    for(int i = 1;i <= n;++i){
        for(int j = L[i].size() - 1,to;j >= 0;--j){
            to = L[i][j];
            
            if(cycle[i] != cycle[to])
                L2[ cycle[i] ].push_back(cycle[to]);
        }
    }
    
    n = cont;
    
    for(int i = 0;i < n;++i)
        L2[i].erase(unique(L2[i].begin(),L2[i].end()),L2[i].end());
    
    memset(visited,false,sizeof visited);
    dfs2(0,0);
    
    for(int i = 0;i < n;++i)
        P[0][i] = p[i];
    
    for(int i = 1;i <= 16;++i)
        for(int j = 0;j < n;++j)
            P[i][j] = P[i - 1][ P[i - 1][j] ];
    
    int Q,u,v;
    
    scanf("%d",&Q);
    
    while(Q--){
        scanf("%d %d",&u,&v);
        u = cycle[u]; v = cycle[v];
        int x = lca(u,v);
        int ret = ans[u] + ans[v] - 2 * ans[x] + (x < ncycles? 1 : 0);
        printf("%d\n",mod_pow(2,ret));
    }
    
    return 0;
}
