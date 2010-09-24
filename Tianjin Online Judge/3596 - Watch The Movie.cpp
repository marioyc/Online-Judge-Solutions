#include <cstdio>
#include <cstring>

using namespace std;

#define max(a,b) (a)>(b)? (a):(b)

int main(){
    int T,N,M,L,t[100],v[100];
    long long dp[2][100][1001];
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;++tc){
        scanf("%d %d %d",&N,&M,&L);
        
        for(int i=0;i<N;++i) scanf("%d %d",&t[i],&v[i]);
        
        memset(dp,-1,sizeof(dp));
        dp[0][0][0] = 0;
        
        for(int i=1;i<=N;++i){
            for(int j=0;j<=M;++j){
                for(int k=0;k<=L;++k){
                    dp[i&1][j][k] = dp[(i&1)^1][j][k];
                    
                    if(k>=t[i-1] && j>0 && dp[(i&1)^1][j-1][k-t[i-1]]!=-1)
                        dp[i&1][j][k] = max(dp[i&1][j][k],v[i-1]+dp[(i&1)^1][j-1][k-t[i-1]]);
                }
            }
        }
        
        long long ans = 0;
        
        for(int i=0;i<=L;++i) ans = max(ans,dp[N&1][M][i]);
        printf("%lld\n",ans);
    }
    
    return 0;
}
