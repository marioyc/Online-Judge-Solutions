#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    
    int dp[60001];
    dp[0] = 0;
    
    for(int i = 1;i<=N;++i){
        dp[i] = i+1;
        
        for(int j = 1;j*j<=i;++j)
            dp[i] = min(dp[i],1+dp[i-j*j]);
    }
    
    printf("%d\n",dp[N]);
    
    return 0;
}
