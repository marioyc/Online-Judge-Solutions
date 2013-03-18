#include <cstdio>
#include <vector>

using namespace std;

#define MAXN 100000

int P[17][MAXN],h[MAXN];
long long w[MAXN];
vector<int> L[MAXN];

void dfs(int cur, int curh){
    h[cur] = curh;
    
    if(cur == 0) w[cur] = 0;
    else w[cur] += w[ P[0][cur] ];
    
    for(int i = L[cur].size() - 1;i >= 0;--i)
        dfs(L[cur][i],curh + 1);
}

int lca(int u, int v){
    if(h[u] < h[v]) swap(u,v);
    
    for(int i = 16;i >= 0;--i)
        if(h[u] - h[v] >= (1 << i))
            u = P[i][u];
    
    for(int i = 16;i >= 0;--i)
        if(P[i][u] != P[i][v]){
            u = P[i][u];
            v = P[i][v];
        }
    
    if(u != v) return P[0][u];
    return u;
}

int main(){
    int N,Q,u,v;
    
    while(true){
        scanf("%d",&N);
        if(N == 0) break;
        
        P[0][0] = 0;
        
        for(int i = 0;i < N;++i)
            L[i].clear();
        
        for(int i = 1;i < N;++i){
            scanf("%d %lld",&P[0][i],&w[i]);
            L[ P[0][i] ].push_back(i);
        }
        
        for(int i = 1;i <= 16;++i)
            for(int j = 0;j < N;++j)
                P[i][j] = P[i - 1][ P[i - 1][j] ];
        
        dfs(0,0);
        
        scanf("%d",&Q);
        
        bool first = true;
        
        while(Q--){
            scanf("%d %d",&u,&v);
            
            int x = lca(u,v);
            
            if(!first) putchar(' ');
            first = false;
            
            printf("%lld",w[u] + w[v] - 2 * w[x]);
        }
        
        putchar('\n');
    }
    
    return 0;
}
