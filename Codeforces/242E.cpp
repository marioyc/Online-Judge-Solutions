#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 100000
#define le(x) 2*x + 1
#define ri(x) 2*x + 2

struct SegmentTree{
    int T[4 * MAXN][20],add[4 * MAXN];
    
    SegmentTree(){}
    
    void push(int node, int l, int r){
        if(add[node] == 0) return;
        
        for(int i = 0;i <= 19;++i)
            if(add[node] & (1 << i))
                T[node][i] = (r - l + 1) - T[node][i];
        
        if(l != r){
            add[le(node)] ^= add[node];
            add[ri(node)] ^= add[node];
        }
        
        add[node] = 0;
    }
    
    void pull(int node){
        for(int i = 0;i <= 19;++i)
            T[node][i] = T[le(node)][i] + T[ri(node)][i];
    }
    
    long long calc(int node){
        long long sum = 0;
        
        for(int i = 19;i >= 0;--i)
            sum = sum * 2 + T[node][i];
        
        return sum;
    }
    
    long long query(int node, int l, int r, int x, int y){
        push(node,l,r);
        if(r < x || l > y) return 0;
        
        if(x <= l && r <= y) return calc(node);
        
        int mi = (l + r) >> 1;
        
        long long ret1 = query(le(node),l,mi,x,y);
        long long ret2 = query(ri(node),mi + 1,r,x,y);
        pull(node);
        
        return ret1 + ret2;
    }
    
    void update(int node, int l, int r, int x, int y, int val){
        push(node,l,r);
        if(r < x || l > y) return;
        
        if(x <= l && r <= y){
            add[node] ^= val;
            push(node,l,r);
        }else{
            int mi = (l + r) >> 1;
            
            update(le(node),l,mi,x,y,val);
            update(ri(node),mi + 1,r,x,y,val);
            pull(node);
        }
    }
}ST;

int main(){
    int n,m,op,l,r,val;
    
    scanf("%d",&n);
    
    for(int i = 0,a;i < n;++i){
        scanf("%d",&a);
        ST.update(0,0,n - 1,i,i,a);
    }
    
    scanf("%d",&m);
    
    while(m--){
        scanf("%d %d %d",&op,&l,&r);
        --l; --r;
        
        if(op == 1){
            printf("%I64d\n",ST.query(0,0,n - 1,l,r));
        }else{
            scanf("%d",&val);
            ST.update(0,0,n - 1,l,r,val);
        }
    }
    
    return 0;
}
