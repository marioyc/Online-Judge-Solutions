#include <cstdio>

using namespace std;

#define MOD 1000000007

int dp[21][1 << 20];

long long mod_pow(long long a, int b){
    long long ret = 1;
    
    while(b){
        if(b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    
    return ret;
}

int main(){
    int n,x;
    
    scanf("%d",&n);
    
    for(int i = 0;i < n;++i){
        scanf("%d",&x);
        ++dp[0][x];
    }
    
    for(int i = 0;i <= 19;++i){
        for(int mask = 0;mask < (1 << 20);++mask){
            dp[i + 1][mask] += dp[i][mask];
            if(dp[i + 1][mask] >= MOD) dp[i + 1][mask] -= MOD;
            
            if(mask & (1 << i)){
                dp[i + 1][mask ^ (1 << i)] += dp[i][mask];
                if(dp[i + 1][mask ^ (1 << i)] >= MOD)
                    dp[i + 1][mask ^ (1 << i)] -= MOD;
            }
        }
    }
    
    int ans = 0;
    
    for(int mask = 0;mask < (1 << 20);++mask){
        if(__builtin_popcount(mask) % 2 == 0){
            ans += mod_pow(2,dp[20][mask]);
            if(ans >= MOD) ans -= MOD;
        }else{
            ans -= mod_pow(2,dp[20][mask]);
            if(ans < 0) ans += MOD;
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}
