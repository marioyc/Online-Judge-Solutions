#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 100000
#define MAXQ 100000
#define MAXVAL 100000
#define MINVAL -100000
#define INF 10000000000LL

int a[MAXN],pos[MAXVAL - MINVAL + 1];
long long best_suff[4 * MAXN],best_old_suff[4 * MAXN],add[4 * MAXN],best_add[4 * MAXN];

void push_down(int node, int l, int r){
    best_old_suff[node] = max(best_old_suff[node],best_suff[node] + best_add[node]);
    best_suff[node] += add[node];
    
    if(l != r){
        best_add[2 * node + 1] = max(best_add[2 * node + 1],add[2 * node + 1] + best_add[node]);
        add[2 * node + 1] += add[node];
        best_add[2 * node + 2] = max(best_add[2 * node + 2],add[2 * node + 2] + best_add[node]);
        add[2 * node + 2] += add[node];
    }
    
    add[node] = 0;
    best_add[node] = 0;
}

long long query(int node, int l, int r, int x, int y){
    push_down(node,l,r);
    if(r < x || l > y) return -INF;
    
    if(x <= l && r <= y){
        return best_old_suff[node];
    }else{
        int mi = (l + r) >> 1;
        
        long long ret1 = query(2 * node + 1,l,mi,x,y);
        long long ret2 = query(2 * node + 2,mi + 1,r,x,y);
        
        best_suff[node] = max(best_suff[2 * node + 1],best_suff[2 * node + 2]);
        best_old_suff[node] = max(best_old_suff[2 * node + 1],best_old_suff[2 * node + 2]);
        
        return max(ret1,ret2);
    }
}

void update(int node, int l, int r, int x, int y, int val){
    push_down(node,l,r);
    if(r < x || l > y) return;
    
    if(x <= l && r <= y){
        add[node] += val;
        best_add[node] = max(best_add[node],add[node]);
        push_down(node,l,r);
    }else{
        int mi = (l + r) >> 1;
        
        update(2 * node + 1,l,mi,x,y,val);
        update(2 * node + 2,mi + 1,r,x,y,val);
        
        best_suff[node] = max(best_suff[2 * node + 1],best_suff[2 * node + 2]);
        best_old_suff[node] = max(best_old_suff[2 * node + 1],best_old_suff[2 * node + 2]);
    }
}

struct query{
    int l,r,id;
    
    query(){}
    query(int _l, int _r, int _id):
        l(_l), r(_r), id(_id){}
    
    bool operator < (query X)const{
        return r < X.r;
    }
}q[MAXQ];

long long ans[MAXQ];

int main(){
    int N;
    scanf("%d",&N);
    
    for(int i = 0;i < N;++i)
        scanf("%d",&a[i]);
    
    int Q;
    scanf("%d",&Q);
    
    for(int i = 0,l,r;i < Q;++i){
        scanf("%d %d",&l,&r);
        q[i].l = l - 1;
        q[i].r = r - 1;
        q[i].id = i;
    }
    
    sort(q,q + Q);
    
    for(int i = 0;i < 4 * N;++i)
        best_old_suff[i] = -INF;
    
    memset(pos,-1,sizeof pos);
    
    for(int i = 0,j = 0;i < N && j < Q;++i){
        update(0,0,N - 1,pos[ a[i] - MINVAL ] + 1,i,a[i]);
        pos[ a[i] - MINVAL ] = i;
        
        while(j < Q && q[j].r == i){
            ans[ q[j].id ] = query(0,0,N - 1,q[j].l,i);
            ++j;
        }
    }
    
    for(int i = 0;i < Q;++i)
        printf("%lld\n",ans[i]);
    
    return 0;
}
