#include <cstdio>

#define MOD 5000011

int main(){    
    int N,K;
    
    scanf("%d %d",&N,&K);
    
    int dp[K+1];
    int M=K+1;
    
    dp[0]=1;
    for(int i=1;i<=N;i++){
        if(i<K+1) dp[i%M]=1;
        dp[i%M]=(dp[i%M]+dp[(i+M-1)%M])%MOD;
    }
    
    printf("%d\n",dp[N%M]);
    
    return 0;
}
