#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int tc = 1,N,a,b,c,dp[2][3];
    
    while(true){
        scanf("%d",&N);
        if(N == 0) break;
        
        scanf("%d %d %d",&a,&b,&c);
        dp[0][0] = 100000000;
        dp[0][1] = b;
        dp[0][2] = b+c;
        
        for(int i = 1,r = 1;i < N;++i,r ^= 1){
            scanf("%d %d %d",&a,&b,&c);
            
            dp[r][0] = a + min(dp[r ^ 1][0], dp[r ^ 1][1]);
            dp[r][1] = b + min(min(dp[r][0], dp[r ^ 1][0]), min(dp[r ^ 1][1], dp[r ^ 1][2]));
            dp[r][2] = c + min(dp[r][1], min(dp[r ^ 1][1], dp[r ^ 1][2]));
        }
        
        printf("%d. %d\n",tc++,dp[(N-1) & 1][1]);
    }
    
    return 0;
}
