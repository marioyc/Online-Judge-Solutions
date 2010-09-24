#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N,F,MOD=100000000;
    
    scanf("%d %d",&N,&F);
    
    int R[N];
    for(int i=0;i<N;i++) scanf("%d",&R[i]);
    
    int dp[2][F];
    
    memset(dp,0,sizeof(dp));
        
    dp[0][0]=1;
    
    for(int i=0;i<N;i++){
        fill(dp[(i+1)&1],dp[(i+1)&1]+F,0);
        for(int j=0;j<F;j++){
            dp[(i+1)&1][(j+R[i])%F]=(dp[(i+1)&1][(j+R[i])%F]+dp[i&1][j])%MOD;
            dp[(i+1)&1][j]=(dp[(i+1)&1][j]+dp[i&1][j])%MOD;
        }
    }
    
    printf("%d\n",(dp[N&1][0]+MOD-1)%MOD);
    
    return 0;
}
