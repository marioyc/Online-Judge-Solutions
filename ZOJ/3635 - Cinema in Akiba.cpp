#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 50000

int bit[MAXN + 1];

void update(int idx){
    for(int x = idx;x <= MAXN;x += x & -x)
        ++bit[x];
}

int query(int idx){
    int ret = 0;
    
    for(int x = idx;x > 0;x -= x & -x)
        ret += bit[x];
    
    return ret;
}

int main(){
    int N,Q,lo,hi,mi,ans[MAXN];
    
    while(scanf("%d",&N) == 1){
        memset(bit,0,sizeof bit);
        
        for(int i = 1,a;i <= N;++i){
            scanf("%d",&a);
            
            lo = 1; hi = N;
            
            while(lo < hi){
                mi = (lo + hi) >> 1;
                
                if(mi - query(mi) < a) lo = mi + 1;
                else hi = mi;
            }
            
            ans[i] = lo;
            update(lo);
        }
        
        scanf("%d",&Q);
        
        for(int i = 0,x;i < Q;++i){
            scanf("%d",&x);
            if(i) putchar(' ');
            printf("%d",ans[x]);
        }
        
        printf("\n");
    }
    
    return 0;
}
