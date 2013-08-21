#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 100000

int a[MAXN],b[MAXN];

bool T1[4 * MAXN];
int T2[4 * MAXN];
bool lazy[4 * MAXN];

void push(int node, int l, int r){
    if(lazy[node]){
        if(l != r){
            int mi = (l + r) >> 1;
            T1[2 * node + 1] = true;
            T2[2 * node + 1] = T2[node];
            lazy[2 * node + 1] = true;
            
            T1[2 * node + 2] = true;
            T2[2 * node + 2] = T2[node] + mi + 1 - l;
            lazy[2 * node + 2] = true;
        }
        
        lazy[node] = false;
    }
}

int query(int node, int l, int r, int x){
    push(node,l,r);
    
    if(l == r){
        if(T1[node]) return a[ T2[node] ];
        else return b[l];
    }else{
        int mi = (l + r) >> 1;
        
        if(x <= mi) return query(2 * node + 1,l,mi,x);
        else return query(2 * node + 2,mi + 1,r,x);
    }
}

void update(int node, int l, int r, int x, int y, int k){
    push(node,l,r);
    if(y > r || y + k - 1 < l) return;
    
    if(y <= l && r <= y + k - 1){
        lazy[node] = true;
        T1[node] = true;
        T2[node] = x + l - y;
        push(node,l,r);
    }else{
        int mi = (l + r) >> 1;
        update(2 * node + 1,l,mi,x,y,k);
        update(2 * node + 2,mi + 1,r,x,y,k);
    }
}

int main(){
    int n,m;
    
    scanf("%d %d",&n,&m);
    
    for(int i = 0;i < n;++i) scanf("%d",&a[i]);
    for(int i = 0;i < n;++i) scanf("%d",&b[i]);
    
    int op,x,y,k;
    
    while(m--){
        scanf("%d",&op);
        
        if(op == 1){
            scanf("%d %d %d",&x,&y,&k);
            --x; --y;
            update(0,0,n - 1,x,y,k);
        }else{
            scanf("%d",&x);
            --x;
            printf("%d\n",query(0,0,n - 1,x));
        }
    }
    
    return 0;
}
