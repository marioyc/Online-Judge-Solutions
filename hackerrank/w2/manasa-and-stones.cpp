#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int T,n,a,b;
    bool dp[2][1000000];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d %d",&n,&a,&b);
        
        memset(dp,false,sizeof dp);
        dp[0][0] = true;
        int last = 0;
        
        for(int i = 1,r = 0;i < n;++i,r ^= 1){
            memset(dp[r ^ 1],false,sizeof dp[r ^ 1]);
            
            for(int j = 0;j <= last;++j)
                if(dp[r][j])
                    dp[r ^ 1][j + a] = true;
            for(int j = 0;j <= last;++j)
                if(dp[r][j])
                    dp[r ^ 1][j + b] = true;
            
            last += max(a,b);
        }
        
        for(int i = 0;i <= last;++i)
            if(dp[(n - 1) & 1][i])
                printf("%d ",i);
        printf("\n");
    }
    
    return 0;
}
