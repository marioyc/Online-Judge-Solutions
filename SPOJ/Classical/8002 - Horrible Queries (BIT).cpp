#include <cstdio>
#include <cstring>

using namespace std;

long long bit1[100002],bit2[100002];

void update(long long bit[], int idx, long long val){
    for(int x = idx;x <= 100001;x += x & -x)
        bit[x] += val;
}

long long query(long long bit[], int idx){
    long long ret = 0;
    
    for(int x = idx;x > 0;x -= x & -x)
        ret += bit[x];
    
    return ret;
}

int main(){
    int T,N,Q;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&N,&Q);
        
        memset(bit1,0,sizeof bit1);
        memset(bit2,0,sizeof bit2);
        
        for(int i = 0,op,l,r,v;i < Q;++i){
            scanf("%d %d %d",&op,&l,&r);
            
            if(op == 0){
                scanf("%d",&v);
                
                update(bit1,l,v); update(bit1,r + 1,-v);
                update(bit2,l,-(long long)v * (l - 1)); update(bit2,r + 1,(long long)v * r);
            }else{
                printf("%lld\n",query(bit1,r) * r + query(bit2,r) - query(bit1,l - 1) * (l - 1) - query(bit2,l - 1));
            }
        }
    }
    
    return 0;
}
