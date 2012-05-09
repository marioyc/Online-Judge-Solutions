#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int n,m;
    bool dp[(1 << 14)];
    
    while(scanf("%d %d",&n,&m) == 2){
        memset(dp,0,sizeof dp);
        dp[0] = 1;
        
        for(int i = 0,k,x;i < n;++i){
            int mask = 0;
            
            scanf("%d",&k);
            
            for(int j = 0;j < k;++j){
                scanf("%d",&x);
                --x;
                mask |= (1 << x);
            }
            
            for(int j = (1 << m) - 1;j >= 0;--j)
                dp[j | mask] |= dp[j];
        }
        
        int ans = 0;
        
        for(int j = (1 << m) - 1;j > 0;--j)
            if(dp[j]) ++ans;
        
        printf("%d\n",ans);
    }
    
    return 0;
}
