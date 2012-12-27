#include <cstdio>
#include <cstring>

using namespace std;

#define MAXM 20
#define MOD 1000000007

int cont[(1 << MAXM)],dp[2][(1 << MAXM)];

int mod_pow(long long a, int b){
    long long ret = 1;
    
    while(b){
        if(b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    
    return ret;
}

int main(){
    int N,M;
    
    scanf("%d %d",&N,&M);
    
    for(int i = 0,k,x;i < N;++i){
        scanf("%d",&k);
        int mask = 0;
        
        for(int j = 0;j < k;++j){
            scanf("%d",&x);
            mask |= (1 << (x - 1));
        }
        
        ++cont[mask];
    }
    
    for(int i = (1 << M) - 1;i >= 0;--i)
        dp[1][i] = cont[i];
    
    for(int i = 0,r = 0;i < M;++i,r ^= 1){
        for(int j = (1 << M) - 1;j >= 0;--j){
            dp[r][j] = dp[r ^ 1][j];
            if(j >> i & 1) dp[r][j] += dp[r ^ 1][j ^ (1 << i)];
        }
    }
    
    int ans = mod_pow(2,N);
    
    for(int mask = 1;mask < (1 << M);++mask){
        int nb = __builtin_popcount(mask);
        
        if(nb & 1){
            ans -= mod_pow(2,dp[(M - 1) & 1][mask ^ ((1 << M) - 1)]);
            if(ans < 0) ans += MOD;
        }else{
            ans += mod_pow(2,dp[(M - 1) & 1][mask ^ ((1 << M) - 1)]);
            if(ans >= MOD) ans -= MOD;
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}
