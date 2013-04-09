#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 105
#define MAXM 10005

int na,a[MAXN],pref[MAXN],suf[MAXN];
int dp[2][MAXM];

int main(){
    int n,m;
    
    scanf("%d %d",&n,&m);
    
    memset(dp,-1,sizeof dp);
    dp[0][0] = 0;
    int sum = 0;
    
    for(int i = 0,r = 1;i < n;++i,r ^= 1){
        scanf("%d",&na);
        
        for(int j = 0;j < na;++j)
            scanf("%d",&a[j]);
        
        pref[0] = suf[0] = 0;
        
        for(int j = 0;j < na;++j){
            pref[j + 1] = pref[j] + a[j];
            suf[j + 1] = suf[j] + a[na - 1 - j];
        }
        
        memset(dp[r],-1,sizeof dp[r]);
        
        for(int j = 0;j <= na;++j){
            int best = 0;
            
            for(int k = 0;k <= j;++k)
                best = max(best,pref[k] + suf[j - k]);
            
            for(int k = 0;k <= sum;++k)
                if(dp[r ^ 1][k] != -1)
                    dp[r][k + j] = max(dp[r][k + j],dp[r ^ 1][k] + best);
        }
        
        sum += na;
    }
    
    printf("%d\n",dp[n & 1][m]);
    
    return 0;
}
