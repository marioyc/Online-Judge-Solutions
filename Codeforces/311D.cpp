#include <cstdio>

using namespace std;

#define MAXN 100000
#define MOD 95542721

int n,a[MAXN];
int T[4 * MAXN][48];
int lazy[4 * MAXN];

void init(int node, int l, int r){
    if(l == r){
        T[node][0] = a[l] % MOD;
        
        for(int i = 1,aux = a[l];i < 48;++i){
            aux = (long long)aux * aux % MOD * aux % MOD;
            T[node][i] = aux;
        }
    }else{
        int mi = (l + r) >> 1;
        init(2 * node + 1,l,mi);
        init(2 * node + 2,mi + 1,r);
        
        for(int i = 0;i < 48;++i){
            int aux = T[2 * node + 1][i] + T[2 * node + 2][i];
            if(aux >= MOD) aux -= MOD;
            T[node][i] = aux;
        }
    }
}

int cop[48];

void push(int node, int l, int r){
    if(lazy[node]){
        int mov = lazy[node] % 48;
        
        for(int i = 0;i < 48;++i)
            cop[i] = T[node][i];
        
        for(int i = 0,pos = mov;i < 48;++i){
            if(pos >= 48) pos -= 48;
            T[node][i] = cop[pos];
            ++pos;
        }
        
        if(l != r){
            lazy[2 * node + 1] += mov;
            lazy[2 * node + 2] += mov;
        }
        
        lazy[node] = 0;
    }
}

void pull(int node){
    for(int i = 0;i < 48;++i){
        int aux = T[2 * node + 1][i] + T[2 * node + 2][i];
        if(aux >= MOD) aux -= MOD;
        T[node][i] = aux;
    }
}

int query(int node, int l, int r, int x, int y){
    push(node,l,r);
    if(y < l || x > r) return 0;
    
    if(x <= l && r <= y){
        return T[node][0];
    }else{
        int mi = (l + r) >> 1;
        
        int ret = query(2 * node + 1,l,mi,x,y) + query(2 * node + 2,mi + 1,r,x,y);
        pull(node);
        
        if(ret >= MOD) ret -= MOD;
        return ret;
    }
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
    //ios::sync_with_stdio(0);
    
    scanf("%d",&n);
    
    for(int i = 0;i < n;++i)
        scanf("%d",&a[i]);
    
    init(0,0,n - 1);
    
    int Q,op,l,r;
    
    scanf("%d",&Q);
    
    while(Q--){
        scanf("%d %d %d",&op,&l,&r);
        --l; --r;
        
        if(op == 1){
            printf("%d\n",query(0,0,n - 1,l,r));
        }else{
            update(0,0,n - 1,l,r);
        }
    }
    
    return 0;
}
