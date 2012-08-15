#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

#define MAXN 100005
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

long long bit0[MAXN],bit1[MAXN],bit2[MAXN];

void update(long long bit[], int idx, long long val){
    for(int x = idx;x < MAXN;x += x & -x)
        bit[x] += val;
}

long long query(long long bit[], int idx){
    long long ret = 0;
    
    for(int x = idx;x > 0;x -= x & -x)
        ret += bit[x];
    
    return ret;
}

void update(int op, int r){
    int l = 1;
    
    if(op == 0){
        update(bit1,l,2 * r + 1);
        update(bit2,l,1);
        
        update(bit0,r + 1,r * (r + 1LL));
        update(bit1,r + 1,-2 * r - 1);
        update(bit2,r + 1,-1);
    }else{
        update(bit1,l,-2 * r - 1);
        update(bit2,l,-1);
        
        update(bit0,r + 1,-r * (r + 1LL));
        update(bit1,r + 1,2 * r + 1);
        update(bit2,r + 1,1);
    }
}

long long query(int l, int r){
    long long ret = 0;
    
    ret = query(bit0,r) + query(bit1,r) * r - query(bit2,r) * r * r;
    ret -= query(bit0,l - 1) + query(bit1,l - 1) * (l - 1) - query(bit2,l - 1) * (l - 1) * (l - 1);
    
    return ret / 2;
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
            
            if(l) update(1,l);
            if(r) update(1,r);
            update(0,l + r + 1);
            
            len[ a[j].second - l ] = l + r + 1;
            len[ a[j].second + r ] = l + r + 1;
            --j;
        }
        
        int e = i;
        
        while(e < Q && q[e].v == v){
            ans[ q[e].id ] = (q[e].a <= q[e].b? query(q[e].a,q[e].b) : 0);
            ++e;
        }
        
        i = e;
    }
    
    for(int i = 0;i < Q;++i)
        printf("%lld\n",ans[i]);
    
    return 0;
}
