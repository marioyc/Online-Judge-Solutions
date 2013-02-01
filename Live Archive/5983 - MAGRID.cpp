#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 500

int R,C,M[MAXN][MAXN];
int dp[MAXN][MAXN];

int main(){
    int T;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&R,&C);
        
        for(int i = 0;i < R;++i)
            for(int j = 0;j < C;++j)
                scanf("%d",&M[i][j]);
        
        int lo = 0,hi = 1000000,mi;
        
        while(lo < hi){
            mi = (lo + hi) >> 1;
            
            memset(dp,0,sizeof dp);
            dp[0][0] = mi;
            
            for(int i = 0;i < R;++i)
                for(int j = 0;j < C;++j){
                    if(i && dp[i - 1][j] > 0)
                        dp[i][j] = max(0,dp[i - 1][j] + M[i][j]);
                    if(j && dp[i][j - 1] > 0)
                        dp[i][j] = max(0,max(dp[i][j],dp[i][j - 1] + M[i][j]));
                }
            
            if(dp[R - 1][C - 1] == 0) lo = mi + 1;
            else hi = mi;
        }
        
        printf("%d\n",lo);
    }
    
    return 0;
}
