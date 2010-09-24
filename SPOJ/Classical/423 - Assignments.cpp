#include <cstdio>
#include <algorithm>

using namespace std;

long long dp[(1<<20)];

int main(){    
    int T,N;
    scanf("%d",&T);
    
    int G[20][20],n,MAX;
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d",&N);
        
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                scanf("%d",&G[i][j]);
        
        fill(dp,dp+(1<<N)+1,0);
        dp[0]=1;
        MAX=(1<<N);
        
        for(int mask=0;mask<MAX-1;mask++){
            n=__builtin_popcount(mask);
            for(int i=0;i<N;i++){
                if(G[n][i]==1 && (mask & (1<<i))==0)
                    dp[mask | (1<<i)]+=dp[mask];
            }
        }
        
        printf("%lld\n",dp[MAX-1]);
    }
    
    return 0;
}
