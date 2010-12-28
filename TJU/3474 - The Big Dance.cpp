#include <cstdio>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    
    long long dp[N+1];
    int pairs[N+1],sum[N+1];
    
    dp[1] = 0; pairs[1] = 0; sum[1] = 0;
    dp[2] = 2; pairs[2] = 1; sum[2] = 1;
    
    for(int i = 3;i<=N;++i){
        int diff = (i+1)>>1,m = pairs[i>>1];
        
        dp[i] = dp[(i+1)>>1]+dp[i>>1]+(long long)m*(diff*diff+diff)+2LL*diff*sum[i>>1];
        pairs[i] = pairs[(i+1)>>1]+pairs[i>>1];
        sum[i] = sum[(i+1)>>1]+sum[i>>1]+m*diff;
    }
    
    printf("%lld\n",dp[N]);
    
    return 0;
}
