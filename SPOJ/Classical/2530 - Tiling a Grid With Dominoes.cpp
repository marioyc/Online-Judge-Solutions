#include <cstdio>

using namespace std;

int main(){
    unsigned int dp[1001];
    dp[0] = dp[1] = 1; dp[2] = 5; dp[3] = 11;
    
    for(int i = 4;i <= 1000;++i)
        dp[i] = dp[i-1]+5*dp[i-2]+dp[i-3]-dp[i-4];
    
    int T,n;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d",&n);
        printf("%d %u\n",tc,dp[n]);
    }
    
    return 0;
}
