#include <cstdio>

using namespace std;

#define MOD 1000000007

long long dp[1000002][16];
int mask2;

int main(){
    dp[1][0] = 1;
    
    for(int i = 1;i <= 1000001;++i){
        for(int mask = 0;mask < 16;++mask){
            dp[i][mask] %= MOD;
            
            if((mask & 1) == 0 && (mask & 2) == 0){
                mask2  = (mask | 3);
                dp[i + 1][mask2 ^ 15] += dp[i][mask];
            }
            
            if((mask & 4) == 0 && (mask & 8) == 0){
                mask2 = (mask | 12);
                dp[i + 1][mask2 ^ 15] += dp[i][mask];
            }
            
            if((mask & 1) == 0 && (mask & 4) == 0){
                mask2 = (mask | 5);
                dp[i + 1][mask2 ^ 15] += dp[i][mask];
            }
            
            if((mask & 2) == 0 && (mask & 8) == 0){
                mask2 = (mask | 10);
                dp[i + 1][mask2 ^ 15] += dp[i][mask];
            }
            
            if(mask == 0) dp[i + 1][0] += 2 * dp[i][0];
            
            dp[i + 1][mask ^ 15] += dp[i][mask];
        }
    }
    
    int T,N;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        printf("%lld\n",dp[N + 1][0]);
    }
    
    return 0;
}
