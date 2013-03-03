#include <cstdio>
#include <vector>

using namespace std;

#define maxn 100001

vector<int> L[maxn];
int in[maxn],out[maxn],cont;

void dfs(int cur, int p){
    in[cur] = cont++;
    
    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i];
        if(to != p) dfs(to,cur);
    }
    
    out[cur] = cont++;
}

int T[4 * 2 * maxn];

int query(int node, int l, int r, int x, int y){
    if(y < l || r < x) return 0;
    if(x <= l && r <= y) return T[node];
    
    int mi = (l + r) >> 1;
    
    return query(2 * node + 1,l,mi,x,y) + query(2 * node + 2,mi + 1,r,x,y);
}

void update(int node, int l, int r, int x, int val){
    if(l == r) T[node] = val;
    else{
        int mi = (l + r) >> 1;
        
        if(x <= mi) update(2 * node + 1,l,mi,x,val);
        else update(2 * node + 2,mi + 1,r,x,val);
        
        T[node] = T[2 * node + 1] + T[2 * node + 2];
    }
}

int main(){
    int n;
    
    scanf("%d",&n);
    
    for(int i = 1,u,v;i < n;++i){
        scanf("%d %d",&u,&v);
        L[u].push_back(v);
        L[v].push_back(u);
    }
    
    cont = 0;
    dfs(1,0);
    
    for(int i = 0,P;i < n;++i){
        scanf("%d",&P);
        printf("%d\n",query(0,0,2 * n - 1,0,in[P]));
        update(0,0,2 * n - 1,in[P],1);
        update(0,0,2 * n - 1,out[P],-1);
    }
    
    return 0;
}
