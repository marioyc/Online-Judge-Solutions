#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int R,C,K;
    char M[300][301];
    int dp[301][301];
    
    while(true){
        scanf("%d %d %d",&R,&C,&K);
        if(R == 0) break;
        
        for(int i = 0;i < R;++i)
            scanf("%s",M[i]);
        
        memset(dp,0,sizeof dp);
        
        for(int i = 0;i < R;++i)
            for(int j = 0;j < C;++j)
                dp[i + 1][j + 1] = (M[i][j] == '.'? 1 : 0) + dp[i][j + 1] + dp[i + 1][j] - dp[i][j];
        
        int ans = R * C;
        
        for(int c1 = 0;c1 < C;++c1){
            for(int c2 = c1;c2 < C;++c2){
                for(int r1 = 0,r2 = 0;r2 < R;++r2){
                    while(r1 < r2 && dp[r2 + 1][c2 + 1] - dp[r1 + 1][c2 + 1] - dp[r2 + 1][c1] + dp[r1 + 1][c1] >= K) ++r1;
                    
                    if(dp[r2 + 1][c2 + 1] - dp[r1][c2 + 1] - dp[r2 + 1][c1] + dp[r1][c1] >= K) ans = min(ans,(c2 - c1 + 1) * (r2 - r1 + 1));
                }
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
