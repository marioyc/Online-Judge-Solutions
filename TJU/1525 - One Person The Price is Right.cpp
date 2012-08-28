#include <cstdio>

using namespace std;

int main(){
    int dp[31][31];
    
    for(int i = 0;i <= 30;++i){
        dp[i][0] = i;
        dp[0][i] = 0;
    }
    
    for(int i = 1;i <= 30;++i)
        for(int j = 1;j <= 30;++j)
            dp[i][j] = dp[i - 1][j] + 1 + dp[i - 1][j - 1];
    
    int tc = 1,G,L;
    
    while(true){
        scanf("%d %d",&G,&L);
        if(G == 0) break;
        
        printf("Case %d: %d\n",tc++,dp[G][L]);
    }
    
    return 0;
}
