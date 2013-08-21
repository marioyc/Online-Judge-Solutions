#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int T[4 * 1000000],lazy[4 * 1000000];

void push(int node, int l, int r){
    T[node] += lazy[node];
    
    if(l != r){
        lazy[2 * node + 1] += lazy[node];
        lazy[2 * node + 2] += lazy[node];
    }
    
    lazy[node] = 0;
}

void pull(int node){
    T[node] = max(T[2 * node + 1],T[2 * node + 2]);
}

int query(int node, int l, int r, int x, int y){
    push(node,l,r);
    if(y < l || x > r) return 0;
    
    if(x <= l && r <= y) return T[node];
    
    int mi = (l + r) >> 1;
    
    int ret1 = query(2 * node + 1,l,mi,x,y);
    int ret2 = query(2 * node + 2,mi + 1,r,x,y);
    pull(node);
    
    return max(ret1,ret2);
}

void update(int node, int l, int r, int x, int y){
    push(node,l,r);
    if(y < l || x > r) return;
    
    if(x <= l && r <= y){
        ++lazy[node];
        push(node,l,r);
    }else{
        int mi = (l + r) >> 1;
        
        update(2 * node + 1,l,mi,x,y);
        update(2 * node + 2,mi + 1,r,x,y);
        pull(node);
    }
}

int main(){
    int TC,K,Q;
    
    scanf("%d",&TC);
    
    for(int tc = 1;tc <= TC;++tc){
        scanf("%d %d",&K,&Q);
        
        memset(T,0,sizeof T);
        memset(lazy,0,sizeof lazy);
        printf("Case %d:\n",tc);
        
        for(int i = 1,a,b;i <= Q;++i){
            scanf("%d %d",&a,&b);
            --a; b -= 2;
            
            if(query(0,0,999999,a,b) < K){
                printf("%d ",i);
                update(0,0,999999,a,b);
            }
        }
        
        printf("\n\n");
    }
    
    return 0;
}
