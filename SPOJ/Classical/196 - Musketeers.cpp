#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int T,n;
    char win[100][101];
    bool dp[100][101];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&n);
        
        for(int i = 0;i < n;++i) scanf("%s",win[i]);
        for(int i = 0;i < n;++i) dp[i][1] = true;
        
        int ans = 0;
        
        for(int len = 2;len <= n;++len){
            for(int i = 0;i < n;++i){
                dp[i][len] = false;
                
                for(int j = 1;j < len;++j){
                    int x = (i + j) % n;
                    
                    if(dp[i][j] && dp[x][len - j] && (win[i][x] == '1' || win[(i + len) % n][x] == '1'))
                        dp[i][len] = true;
                }
                
                if(len == n && dp[i][len]) ++ans;
            }
        }
        
        printf("%d\n",ans);
        
        for(int i = 0;i < n;++i)
            if(dp[i][n]) printf("%d\n",i + 1);
    }
    
    return 0;
}
