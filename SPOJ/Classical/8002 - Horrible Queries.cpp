#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long sum[4 * 100000],childSum[4 * 100000];

long long query(int node, int l, int r, int a, int b){
    if(l > b || r < a) return 0;
    
    long long ret = (min(b,r) - max(a,l) + 1) * sum[node];
    
    if(a <= l && r <= b) ret += childSum[node];
    else{
        int mi = (l + r) >> 1;
        
        ret += query(2 * node + 1,l,mi,a,b) + query(2 * node + 2,mi + 1,r,a,b);
    }
    
    return ret;
}

void update(int node, int l, int r, int a, int b, int x){
    if(l > b || r < a) return;
    
    if(a <= l && r <= b) sum[node] += x;
    else{
        int mi = (l + r) >> 1;
        
        update(2 * node + 1,l,mi,a,b,x);
        update(2 * node + 2,mi + 1,r,a,b,x);
        
        childSum[node] = childSum[2 * node + 1] + childSum[2 * node + 2] + (mi - l + 1) * sum[2 * node + 1] + (r - mi) * sum[2 * node + 2];
    }
}

int main(){
    int TC,N,C;
    int op,p,q,v;
    
    scanf("%d",&TC);
    
    while(TC--){
        scanf("%d %d",&N,&C);
        
        memset(sum,0,sizeof sum);
        memset(childSum,0,sizeof childSum);
        
        for(int i = 0;i < C;++i){
            scanf("%d",&op);
            
            if(op == 0){
                scanf("%d %d %d",&p,&q,&v);
                
                update(0,1,N,p,q,v);
            }else{
                scanf("%d %d",&p,&q);
                
                printf("%lld\n",query(0,1,N,p,q));
            }
        }
    }
    
    return 0;
}
