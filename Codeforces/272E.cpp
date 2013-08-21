#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 300000

vector<int> L[MAXN];
int g[MAXN],c[MAXN],T[4 * MAXN];

void init(int node, int l, int r){
    if(l == r) T[node] = l;
    else{
        int mi = (l + r) >> 1;
        init(2 * node + 1,l,mi);
        init(2 * node + 2,mi + 1,r);
        
        int x = T[2 * node + 1],y = T[2 * node + 2];
        
        if(g[x] > g[y]) T[node] = x;
        else T[node] = y;
    }
}

void update(int node, int l, int r, int pos, int val){
    if(r < pos || l > pos) return;
    
    if(l == r) g[l] += val;
    else{
        int mi = (l + r) >> 1;
        update(2 * node + 1,l,mi,pos,val);
        update(2 * node + 2,mi + 1,r,pos,val);
        
        int x = T[2 * node + 1],y = T[2 * node + 2];
        
        if(g[x] > g[y]) T[node] = x;
        else T[node] = y;
    }
}

int main(){
    int n,m;
    
    scanf("%d %d",&n,&m);
    
    for(int i = 0,u,v;i < m;++i){
        scanf("%d %d",&u,&v);
        --u; --v;
        ++g[u]; ++g[v];
        L[u].push_back(v);
        L[v].push_back(u);
    }
    
    for(int i = 0;i < n;++i) c[i] = 0;
    init(0,0,n - 1);
    
    while(true){
        int u = T[0];
        
        if(g[u] > 1){
            int cont = 0;
            
            for(int i = L[u].size() - 1,to;i >= 0;--i){
                to = L[u][i];
                ++cont;
                if(c[to] == c[u]) update(0,0,n - 1,to,-1);
                else update(0,0,n - 1,to,1);
            }
            
            update(0,0,n - 1,u,cont - 2 * g[u]);
            c[u] ^= 1;
        }else break;
    }
    
    for(int i = 0;i < n;++i) printf("%d",c[i]);
    printf("\n");
    
    return 0;
}
