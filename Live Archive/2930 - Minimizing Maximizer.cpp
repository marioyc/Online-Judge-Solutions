#include <cstdio>
#include <algorithm>

using namespace std;

#define INF 500001

int N,A[200000];

int query(int node, int l, int r, int a, int b){
    if(r < a || l > b) return INF;
    if(a <= l && r <= b) return A[node];
    
    int mi = (l + r) >> 1;
    
    return min(query(2*node + 1,l,mi,a,b), query(2*node + 2,mi + 1,r,a,b));
}

void update(int x, int val){
    int node = 0,l = 0,r = N - 1,mi;
    
    A[node] = min(A[node],val);
    
    while(l != r){
        mi = (l + r) >> 1;
        
        if(x <= mi){
            r = mi;
            node = 2*node + 1;
        }else{
            l = mi + 1;
            node = 2*node + 2;
        }
        
        A[node] = min(A[node],val);
    }
}

int main(){
    int T,M;
    bool first = true;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&N,&M);
        
        for(int i = 4*N;i >= 0;--i) A[i] = INF;
        update(0,0);
        
        for(int i = 0,a,b;i < M;++i){
            scanf("%d %d",&a,&b);
            --a; --b;
            
            int best = query(0,0,N - 1,a,b - 1);
            if(best != INF) update(b,best + 1);
        }
        
        if(!first) printf("\n");
        first = false;
        
        printf("%d\n",query(0,0,N - 1,N - 1,N - 1));
    }
    
    return 0;
}
