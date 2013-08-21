#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

long long dp[100000][2][3];
int cap[100000];

int main(){
    int N;
    
    scanf("%d",&N);
    
    for(int i = 0;i < N - 1;++i)
        scanf("%d",&cap[i]);
    
    memset(dp,-1,sizeof dp);
    
    for(int i = 0;i < N;++i)
        dp[i][0][0] = 0;
    
    long long ans = 0;
    
    for(int i = 0;i + 1 < N;++i){
        for(int p = 0;p < 2;++p){
            for(int odd = 0;odd <= 2;++odd){
                if(dp[i][p][odd] != -1){
                    int deg = odd;
                    int odd2 = odd + (deg % 2 == 1? 1 : 0);
                    
                    if(odd2 <= 2 && cap[i] >= 2){
                        dp[i + 1][0][odd2] = max(dp[i + 1][0][odd2],(cap[i] % 2 == 0? cap[i] : cap[i] - 1) + dp[i][p][odd]);
                        if(odd2 == 0 || odd2 == 2) ans = max(ans,dp[i + 1][0][odd2]);
                    }
                    
                    deg = (deg + 1) % 2;
                    odd2 = odd + (deg % 2 == 1? 1 : 0);
                    
                    if(odd2 <= 2 && cap[i] >= 1){
                        dp[i + 1][1][odd2] = max(dp[i + 1][1][odd2],(cap[i] % 2 == 1? cap[i] : cap[i] - 1) + dp[i][p][odd]);
                        if(odd2 == 1) ans = max(ans,dp[i + 1][1][odd2]);
                    }
                }
            }
        }
    }
    
    printf("%I64d\n",ans);
    
    return 0;
}
