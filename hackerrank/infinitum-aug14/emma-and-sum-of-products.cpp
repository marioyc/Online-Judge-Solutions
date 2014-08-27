#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 30000
#define MOD 100003

int a[MAXN];
long long dp[2][MAXN + 1];

int main(){
    int N;
    
    scanf("%d",&N);
    
    for(int i = 0;i < N;++i)
        scanf("%d",&a[i]);
    
    dp[0][0] = 1;
    dp[0][1] = a[0];
    
    for(int i = 1,r = 1;i < N;++i,r ^= 1){
        memset(dp[r],0,sizeof dp[r]);
        dp[r][0] = 1;
        
        for(int k = 1;k <= i + 1;++k)
            dp[r][k] = (dp[r ^ 1][k] + dp[r ^ 1][k - 1] * a[i]) % MOD;
    }
    
    int Q,K;
    
    scanf("%d",&Q);
    
    while(Q--){
        scanf("%d",&K);
        printf("%lld\n",dp[(N - 1) & 1][K]);
    }
    
    return 0;
}
