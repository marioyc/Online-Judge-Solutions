#include <cstdio>

using namespace std;

int main(){
    int N,K;
    scanf("%d %d",&N,&K);
    
    long long dp[43][2];
    dp[0][0] = dp[0][1] = 1;
    
    for(int i = 1;i<N;++i){
        dp[i][0] = (dp[i-1][0] + dp[i-1][1]>K? K : dp[i-1][0] + dp[i-1][1]);
        dp[i][1] = dp[i-1][0];
    }
    
    if(dp[N-1][0]+dp[N-1][1]<K) printf("-1\n");
    else{
        for(int i = N-1;i>=0;--i){
            if(dp[i][0]>=K){
                putchar('0');
            }else{
                putchar('1');
                if(i>0)putchar('0');
                K -= dp[i][0];
                --i;
            }
        }
        putchar('\n');
    }
    
    return 0;
}
