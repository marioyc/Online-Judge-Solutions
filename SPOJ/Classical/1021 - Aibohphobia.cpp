#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int T,L,dp[2][6101];
    char s[6002];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%s",s);
        L = strlen(s);
        
        memset(dp,0,sizeof(dp));
        
        for(int i = L-1;i >= 0;--i){
            int r = i & 1;
            
            for(int j = 0;j < L;++j){
                dp[r][L-1-j] = max(dp[r][L-j],dp[r ^ 1][L-1-j]);
                if(s[i] == s[j]) dp[r][L-1-j] = max(dp[r][L-1-j],1+dp[r ^ 1][L-j]);
            }
        }
        
        printf("%d\n",L-dp[0][0]);
    }
    
    return 0;
}
