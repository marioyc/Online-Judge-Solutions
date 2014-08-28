#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 30005
#define MAXM 50005

struct edge{
    int u,v,a;
    
    edge(){}
    
    bool operator < (edge X)const{
        return a > X.a;
    }
}e[MAXM];

int parent[MAXN];

int Find(int x){
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}

vector<int> L[MAXN];
int h[MAXN],p[15][MAXN],mn[15][MAXN],mx[15][MAXN],best[15][MAXN],best2[15][MAXN];

void dfs(int cur, int par, int lvl){
    h[cur] = lvl;
    p[0][cur] = par;
    
    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i];
        if(to != par) dfs(to,cur,lvl + 1);
    }
}

int lca(int u, int v){
    if(h[v] > h[u]) swap(u,v);
    
    int diff = h[u] - h[v];
    
    for(int i = 14;i >= 0;--i)
        if(diff & (1 << i))
            u = p[i][u];
    
    for(int i = 14;i >= 0;--i)
        if(p[i][u] != p[i][v]){
            u = p[i][u];
            v = p[i][v];
        }
    
    if(u == v) return u;
    return p[0][u];
}

int main(){
    int N,M,b[MAXN],Q,X,Y,Z;
    
    while(scanf("%d",&N) == 1){
        for(int i = 1;i <= N;++i)
            scanf("%d",&b[i]);
        
        scanf("%d",&M);
        
        for(int i = 0;i < M;++i)
            scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].a);
        
        sort(e,e + M);
        
        for(int i = 1;i <= N;++i){
            parent[i] = i;
            L[i].clear();
        }
        
        long long sum = 0;
        
        for(int i = 0,u,v;i < M;++i){
            u = Find(e[i].u); v = Find(e[i].v);
            
            if(u != v){
                parent[u] = v;
                L[ e[i].u ].push_back(e[i].v);
                L[ e[i].v ].push_back(e[i].u);
                sum += e[i].a;
            }
        }
        
        printf("%lld\n",sum);
        
        dfs(1,0,0);
        
        for(int i = 1;i <= N;++i){
            mn[0][i] = mx[0][i] = b[i];
            best[0][i] = 0;
        }
        
        for(int i = 1;i <= 14;++i){
            for(int j = 1;j <= N;++j){
                p[i][j] = p[i - 1][ p[i - 1][j] ];
                mn[i][j] = min(mn[i - 1][j],mn[i - 1][ p[i - 1][j] ]);
                mx[i][j] = max(mx[i - 1][j],mx[i - 1][ p[i - 1][j] ]);
                best[i][j] = max(max(best[i - 1][j],best[i - 1][ p[i - 1][j] ]),mx[i - 1][ p[i - 1][j] ] - mn[i - 1][j]);
                best2[i][j] = max(max(best2[i - 1][j],best2[i - 1][ p[i - 1][j] ]),mx[i - 1][j] - mn[i - 1][ p[i - 1][j] ]);
            }
        }
        
        scanf("%d",&Q);
        
        while(Q--){
            scanf("%d %d",&X,&Y);
            Z = lca(X,Y);
            
            vector<int> mn1,mx1,mn2,mx2;
            int n1 = 0,n2 = 0,ans = 0;
            
            int diff = h[X] - h[Z] + 1;
            
            for(int i = 14;i >= 0;--i){
                if(diff & (1 << i)){
                    mn1.push_back(mn[i][X]);
                    mx1.push_back(mx[i][X]);
                    ans = max(ans,best[i][X]);
                    X = p[i][X];
                    ++n1;
                }
            }
            
            diff = h[Y] - h[Z] + 1;
            
            for(int i = 14;i >= 0;--i){
                if(diff & (1 << i)){
                    mn2.push_back(mn[i][Y]);
                    mx2.push_back(mx[i][Y]);
                    ans = max(ans,best2[i][Y]);
                    Y = p[i][Y];
                    ++n2;
                }
            }
            
            int x = 100000;
            
            for(int i = 0;i < n1;++i){
                ans = max(ans,mx1[i] - x);
                x = min(x,mn1[i]);
            }
            
            for(int i = n2 - 1;i >= 0;--i){
                ans = max(ans,mx2[i] - x);
                x = min(x,mn2[i]);
            }
            
            printf("%d\n",ans);
        }
    }
    
    return 0;
}
