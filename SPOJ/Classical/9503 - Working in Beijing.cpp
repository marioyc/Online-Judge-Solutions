#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T,n,a,b,t;
    long long dp,f;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d %d %d",&n,&a,&b);
        
        f = (1LL << 62);
        
        for(int i = 0;i < n;++i){
            scanf("%d",&t);
            
            f = min(f,(i > 0? dp : 0) - b * t);
            
            dp = b * t + 2LL * a + b + f;
        }
        
        printf("Case #%d: %lld\n",tc,dp);
    }
    
    return 0;
}
