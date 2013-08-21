#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 505
#define MAXM 10001
#define MAXQ 20001

int parent[MAXN],comp,C;
int rank[MAXN];

int Find(int x){
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int x, int y){
    if(comp == C) return;
    x = Find(x); y = Find(y);
    
    if(x != y){
        if(rank[x] < rank[y]) parent[x] = y;
        else{
            if(rank[x] == rank[y]) ++rank[x];
            parent[y] = x;
        }
        --comp;
    }
}

int u[MAXM],v[MAXM];

struct query{
    int l,r,id;
    
    query(){}
    
    bool operator < (query X)const{
        if(l != X.l) return l < X.l;
        return r > X.r;
    }
};

query q[MAXQ];
int ans[MAXQ];

int main(){
    int n,m;
    
    scanf("%d %d",&n,&m);
    
    for(int i = 1;i <= n;++i)
        parent[i] = i;
    memset(rank,0,sizeof rank);
    comp = n;
    
    for(int i = 1;i <= m;++i){
        scanf("%d %d",&u[i],&v[i]);
        Union(u[i],v[i]);
    }
    
    C = comp;
    
    int Q,l,r;
    
    scanf("%d",&Q);
    
    for(int i = 0;i < Q;++i){
        scanf("%d %d",&l,&r);
        q[i].l = l;
        q[i].r = r;
        q[i].id = i;
    }
    
    sort(q,q + Q);
    
    for(int l = 1,pos = 0;l <= m && pos < Q;++l){
        if(q[pos].l == l){
            for(int i = 1;i <= n;++i)
                parent[i] = i;
            memset(rank,0,sizeof rank);
            comp = n;
            
            for(int i = 1;i < l;++i)
                Union(u[i],v[i]);
            
            for(int r = m;r >= l && pos < Q && q[pos].l == l;--r){
                while(pos < Q && q[pos].l == l && q[pos].r == r){
                    ans[ q[pos].id ] = comp;
                    ++pos;
                }
                Union(u[r],v[r]);
            }
        }
    }
    
    for(int i = 0;i < Q;++i)
        printf("%d\n",ans[i]);
    
    return 0;
}
