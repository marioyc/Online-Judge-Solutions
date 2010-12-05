#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int A,B;
    scanf("%d %d",&A,&B);
    
    int N = B-A+1,f[100001];
    
    for(int i = 0;i<N;++i)
        scanf("%d",&f[i]);
    
    int dp[2][2];
    
    dp[0][0] = dp[0][1] = 1;
    
    for(int i = 1;i<N;++i){
        dp[i & 1][0] = dp[i & 1][1] = N;
        
        if(f[i]>=f[i-1]) dp[i & 1][0] = min(dp[(i & 1) ^ 1][0],1+dp[(i & 1) ^ 1][1]);
        else dp[i & 1][0] = 1+min(dp[(i & 1) ^ 1][0],dp[(i & 1) ^ 1][1]);
        
        if(f[i]<=f[i-1]) dp[i & 1][1] = min(dp[(i & 1) ^ 1][1],1+dp[(i & 1) ^ 1][0]);
        else dp[i & 1][1] = 1+min(dp[(i & 1) ^ 1][1],dp[(i & 1) ^ 1][0]);
    }
    
    printf("%d\n",min(dp[(N-1) & 1][0],dp[(N-1) & 1][1]));
    
    return 0;
}
