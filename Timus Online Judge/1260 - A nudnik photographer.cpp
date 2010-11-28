#include <cstdio>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    
    int dp[56];
    dp[1] = dp[2] = 1;
    dp[3] = 2;
    
    for(int i = 4;i<=N;++i)
        dp[i] = dp[i-1]+dp[i-3]+1;
    
    printf("%d\n",dp[N]);
    
    return 0;
}
