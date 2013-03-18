#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 1000

int x[MAXN],y[MAXN],p[MAXN];
double w[MAXN][MAXN];

struct edge{
    int u,v;
    double w;
    
    edge(){}
    edge(int _u, int _v, double _w):
        u(_u), v(_v), w(_w){}
    
    bool operator < (edge X)const{
        return w < X.w;
    }
}E[MAXN * MAXN];

int parent[MAXN];

int Find(int x){
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int x, int y){
    x = Find(x); y = Find(y);
    if(x != y) parent[x] = y;
}

vector<int> L[MAXN];
int h[MAXN],P[10][MAXN];
double W[10][MAXN];

void dfs(int cur, int p, int curh = 0){
    h[cur] = curh;
    P[0][cur] = p;
    W[0][cur] = w[cur][p];
    
    for(int i = 1;i <= 9;++i){
        P[i][cur] = P[i - 1][ P[i - 1][cur] ];
        W[i][cur] = max(W[i - 1][cur],W[i - 1][ P[i - 1][cur] ]);
    }
    
    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i];
        if(to != p) dfs(to,cur,curh + 1);
    }
}

int lca(int u, int v){
    if(h[u] < h[v]) swap(u,v);
    
    int dh = h[u] - h[v];
    
    for(int i = 9;i >= 0;--i)
        if(dh >> i & 1)
            u = P[i][u];
    
    for(int i = 9;i >= 0;--i)
        if(P[i][u] != P[i][v])
            u = P[i][u], v = P[i][v];
    
    if(u != v) u = P[0][u], v = P[0][v];
    return u;
}

double solve(int u, int v){
    int anc = lca(u,v);
    double ans = 0;
    
    int dh = h[u] - h[anc];
    
    for(int i = 9;i >= 0;--i)
        if(dh >> i & 1){
            ans = max(ans,W[i][u]);
            u = P[i][u];
        }
    
    dh = h[v] - h[anc];
    
    for(int i = 9;i >= 0;--i)
        if(dh >> i & 1){
            ans = max(ans,W[i][v]);
            v = P[i][v];
        }
    
    return ans;
}

int main(){
    int T,n;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&n);
        
        int ne = 0;
        
        for(int i = 0;i < n;++i){
            scanf("%d %d %d",&x[i],&y[i],&p[i]);
            w[i][i] = 0;
            
            for(int j = 0;j < i;++j){
                w[i][j] = w[j][i] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
                E[ne++] = edge(i,j,w[i][j]);
            }
        }
        
        sort(E,E + ne);
        
        for(int i = 0;i < n;++i){
            parent[i] = i;
            L[i].clear();
        }
        
        double cost = 0;
        
        for(int i = 0;i < ne;++i){
            if(Find(E[i].u) != Find(E[i].v)){
                cost += E[i].w;
                Union(E[i].u,E[i].v);
                L[ E[i].u ].push_back(E[i].v);
                L[ E[i].v ].push_back(E[i].u);
            }
        }
        
        dfs(0,0);
        
        double ans = 0;
        
        for(int i = 0;i < n;++i)
            for(int j = i + 1;j < n;++j)
                ans = max(ans,(p[i] + p[j]) / (cost - solve(i,j)));
        
        printf("%.2f\n",ans);
    }
    
    return 0;
}
