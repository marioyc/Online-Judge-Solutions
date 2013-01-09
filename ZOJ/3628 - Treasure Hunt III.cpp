#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 50000
#define INF 1000000000000000LL

int n,T,s;
int a[2 * MAXN];
long long dp[17][2 * MAXN][2][2];
long long dp2[17][2][2];

long long solve(int l, int r){
    int len = r - l + 1;
    int m = 0;
    
    for(int i = 0;i <= 16;++i){
        if(len >> i & 1){
            if(m == 0){
                dp2[0][0][0] = dp[i][l][0][0];
                dp2[0][0][1] = dp[i][l][0][1];
                dp2[0][1][0] = dp[i][l][1][0];
                dp2[0][1][1] = dp[i][l][1][1];
            }else{
                dp2[m][0][0] = max(-INF,max(dp2[m - 1][0][0] + max(dp[i][l][0][0],dp[i][l][1][0]),dp2[m - 1][0][1] + dp[i][l][0][0]));
                dp2[m][0][1] = max(-INF,max(dp2[m - 1][0][0] + max(dp[i][l][0][1],dp[i][l][1][1]),dp2[m - 1][0][1] + dp[i][l][0][1]));
                dp2[m][1][0] = max(-INF,max(dp2[m - 1][1][0] + max(dp[i][l][0][0],dp[i][l][1][0]),dp2[m - 1][1][1] + dp[i][l][0][0]));
                dp2[m][1][1] = max(-INF,max(dp2[m - 1][1][0] + max(dp[i][l][0][1],dp[i][l][1][1]),dp2[m - 1][1][1] + dp[i][l][0][1]));
            }
            
            l += (1 << i);
            ++m;
        }
    }
    
    long long ret = max(max(dp2[m - 1][0][0],dp2[m - 1][0][1]),dp2[m - 1][1][0]);
    if(len < n) ret = max(ret,dp2[m - 1][1][1]);
    return ret;
}

int main(){
    while(scanf("%d %d %d",&n,&T,&s) == 3){
        for(int i = 0;i < n;++i) scanf("%d",&a[i]);
        for(int i = 0;i < n;++i) a[n + i] = a[i];
        
        int N = 2 * n;
        
        for(int i = 0;i < N;++i){
            dp[0][i][0][0] = 0;
            dp[0][i][0][1] = -INF;
            dp[0][i][1][0] = -INF;
            dp[0][i][1][1] = a[i];
        }
        
        for(int i = 1;(1 << i) <= N;++i){
            int sz = (1 << i);
            
            for(int j = 0,k = (1 << (i - 1));j + sz - 1 < N;++j,++k){
                long long best0 = max(dp[i - 1][k][0][0],dp[i - 1][k][1][0]);
                long long best1 = max(dp[i - 1][k][0][1],dp[i - 1][k][1][1]);
                dp[i][j][0][0] = max(-INF,max(dp[i - 1][j][0][0] + best0,dp[i - 1][j][0][1] + dp[i - 1][k][0][0]));
                dp[i][j][0][1] = max(-INF,max(dp[i - 1][j][0][0] + best1,dp[i - 1][j][0][1] + dp[i - 1][k][0][1]));
                dp[i][j][1][0] = max(-INF,max(dp[i - 1][j][1][0] + best0,dp[i - 1][j][1][1] + dp[i - 1][k][0][0]));
                dp[i][j][1][1] = max(-INF,max(dp[i - 1][j][1][0] + best1,dp[i - 1][j][1][1] + dp[i - 1][k][0][1]));
            }
        }
        
        --s;
        long long ans = 0;
        
        for(int i = 0;i < n && i <= T;++i){
            int l = s + n - i;
            int r = min(l + n - 1,s + n + (T - i) / 2);
            
            if(2 * i <= T)
                r = max(r,min(l + n - 1,s + n + T - 2 * i));
            
            if(l >= n) l -= n,r -= n;
            ans = max(ans,solve(l,r));
        }
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
