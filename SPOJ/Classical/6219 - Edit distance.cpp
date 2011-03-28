#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int T,L1,L2,dp[2][2001];
    char s1[2001],s2[2001];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%s %s",s1,s2);
        L1 = strlen(s1);
        L2 = strlen(s2);
        
        memset(dp,0,sizeof(dp));
        for(int i = 0,r = (L1 & 1);i <= L2;++i) dp[r][i] = L2-i;
        
        for(int i = L1-1,r;i >= 0;--i){
            r = (i & 1);
            
            dp[r][L2] = L1-i;
            
            for(int j = L2-1;j >= 0;--j){
                if(s1[i] == s2[j]) dp[r][j] = dp[r ^ 1][j+1];
                else dp[r][j] = 1 + min(dp[r ^ 1][j+1],min(dp[r][j+1],dp[r ^ 1][j]));
            }
        }
        
        printf("%d\n",dp[0][0]);
    }
    
    return 0;
}
