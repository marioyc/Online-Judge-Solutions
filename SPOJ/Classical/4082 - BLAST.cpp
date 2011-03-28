#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int L1,L2,K,dp[2][2001];
    char A[2001],B[2001];
    
    scanf("%s %s %d",A,B,&K);
    
    L1 = strlen(A);
    L2 = strlen(B);
    
    memset(dp,0,sizeof(dp));
    
    int r = L1 & 1;
    for(int j = 0;j < L2;++j) dp[r][j] = K * (L2-j);
    r ^= 1;
    
    for(int i = L1-1;i >= 0;--i,r ^= 1){
        dp[r][L2] = K * (L1-i);
        
        for(int j = L2-1;j >= 0;--j)
            dp[r][j] = min(abs(A[i]-B[j]) + dp[r ^ 1][j+1],K + min(dp[r][j+1],dp[r ^ 1][j]));
    }
    
    printf("%d\n",dp[0][0]);
    
    return 0;
}
