#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_W = 800 * 1000;
int dp[2][22][80],cap1[1000],cap2[1000],w[1000];

int main(){
    int T,OX,NI,n;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d %d",&OX,&NI,&n);
        
        for(int i = 0;i < n;++i)
            scanf("%d %d %d",&cap1[i],&cap2[i],&w[i]);
        
        for(int i = 0;i <= OX;++i)
            for(int j = 0;j <= NI;++j)
                dp[1][i][j] = MAX_W;
        
        dp[1][0][0] = 0;
        
        for(int i = 0,r = 0;i < n;++i,r ^= 1)
            for(int ox = 0;ox <= OX;++ox)
                for(int ni = 0;ni <= NI;++ni)
                    dp[r][ox][ni] = min(dp[r ^ 1][ox][ni],w[i] + dp[r ^ 1][max(0,ox-cap1[i])][max(0,ni-cap2[i])]);
        
        printf("%d\n",dp[(n-1) & 1][OX][NI]);
    }
    
    return 0;
}
