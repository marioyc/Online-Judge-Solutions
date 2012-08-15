#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

#define MAXN 100000
#define MAXQ 100000

struct query{
    int v,a,b,id;
    
    query(){}
    
    bool operator < (query X)const{
        return v > X.v;
    }
}q[MAXQ];

pair<int,int> a[MAXN];
int len[MAXN];
long long ans[MAXQ];

long long T[4 * MAXN];
int add[4 * MAXN],radd[4 * MAXN];

void fix(int node, int a, int b){
    int n = b - a + 1;
    
    T[node] += (2LL * add[node] + (n - 1LL) * radd[node]) * n / 2;
    
    if(a != b){
        int mi = (a + b) >> 1;
        
        add[2 * node + 1] += add[node]; radd[2 * node + 1] += radd[node];
        add[2 * node + 2] += add[node] + (mi + 1 - a) * radd[node]; radd[2 * node + 2] += radd[node];
    }
    
    add[node] = radd[node] = 0;
}

long long query(int node, int a, int b, int l, int r){
    fix(node,a,b);
    if(b < l || a > r) return 0;
    
    if(a >= l && b <= r) return T[node];
    else{
        int mi = (a + b) >> 1;
        
        return query(2 * node + 1,a,mi,l,r) + query(2 * node + 2,mi + 1,b,l,r);
    }
}

void update(int node, int a, int b, int l, int r, int a0, int ra){
    fix(node,a,b);
    if(b < l || a > r) return;
    
    if(a >= l && b <= r){
        add[node] = a0 + ra * (a - l);
        radd[node] = ra;
        fix(node,a,b);
    }else{
        int mi = (a + b) >> 1;
        
        update(2 * node + 1,a,mi,l,r,a0,ra);
        update(2 * node + 2,mi + 1,b,l,r,a0,ra);
        
        T[node] = T[2 * node + 1] + T[2 * node + 2];
    }
}

int main(){
    int N,Q;
    
    scanf("%d %d",&N,&Q);
    
    for(int i = 0;i < N;++i){
        scanf("%d",&a[i].first);
        a[i].second = i;
    }
    
    sort(a,a + N);
    
    for(int i = 0;i < Q;++i){
        scanf("%d %d %d",&q[i].v,&q[i].a,&q[i].b);
        q[i].b = min(N,q[i].b);
        q[i].id = i;
    }
    
    sort(q,q + Q);
    
    for(int i = 0,j = N - 1;i < Q;){
        int v = q[i].v;
        
        while(j >= 0 && a[j].first >= v){
            int l = 0,r = 0;
            
            if(a[j].second > 0) l = len[ a[j].second - 1 ];
            if(a[j].second + 1 < N) r = len[ a[j].second + 1];
            
            if(l) update(0,0,N - 1,0,l - 1,-l,1);
            if(r) update(0,0,N - 1,0,r - 1,-r,1);
            update(0,0,N - 1,0,l + r,l + r + 1,-1);
            
            len[ a[j].second - l ] = l + r + 1;
            len[ a[j].second + r ] = l + r + 1;
            --j;
        }
        
        int e = i;
        
        while(e < Q && q[e].v == v){
            ans[ q[e].id ] = (q[e].a <= q[e].b? query(0,0,N - 1,q[e].a - 1,q[e].b - 1) : 0);
            ++e;
        }
        
        i = e;
    }
    
    for(int i = 0;i < Q;++i)
        printf("%lld\n",ans[i]);
    
    return 0;
}
