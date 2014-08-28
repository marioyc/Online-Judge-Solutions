#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 100005

int main(){
    int n,p,v[MAXN],M,T;
    long long sum[MAXN];
    
    while(scanf("%d %d",&n,&p) == 2){
        sum[0] = 0;
        
        for(int i = 0;i < n;++i){
            scanf("%d",&v[i]);
            sum[i + 1] = sum[i] +v[i];
        }
        
        scanf("%d %d",&M,&T);
        
        long long ans = 0;
        
        for(int i = 1;i <= p;++i){
            int lo = p - 1,hi = n,mi;
            
            while(lo < hi){
                mi = (lo + hi + 1) >> 1;
                
                int z1 = min(mi,min(2 * p - i,i + M));
                int t1 = p - i + mi - z1;
                
                int z2 = max(i,max(2 * p - mi,mi - M));
                int t2 = mi - p + z2 - i;
                
                if(min(t1,t2) > T) hi = mi - 1;
                else lo = mi;
            }
            
            if(lo >= p) ans = max(ans,sum[lo] - sum[i - 1]);
        }
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
