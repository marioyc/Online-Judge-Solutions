#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXVAL 41200

int dp[MAXVAL];

int main(){
    int T,C,Y,n;
    int val[10],win[10];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d %d",&C,&Y,&n);
        
        for(int i = 0;i < n;++i){
            scanf("%d %d",&val[i],&win[i]);
            val[i] /= 1000;
        }
        
        memset(dp,0,sizeof dp);
        
        for(int j = 0;j < n;++j)
            for(int i = val[j];i < MAXVAL;++i)
                dp[i] = max(dp[i],dp[i - val[j]] + win[j]);
        
        for(int i = 1;i < MAXVAL;++i)
            dp[i] = max(dp[i],dp[i - 1]);
        
        for(int i = 0;i < Y;++i)
            C += dp[C / 1000];
        
        printf("%d\n",C);
    }
    
    return 0;
}
