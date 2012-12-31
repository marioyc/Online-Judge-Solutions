#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1000000

int dp[2][2];
char s[MAXN + 1];

int main(){
    int N;
    
    scanf("%d %s",&N,s);
    
    if(s[0] == 'A'){
        dp[0][0] = 0;
        dp[0][1] = 2;
    }else{
        dp[0][0] = 1;
        dp[0][1] = 1;
    }
    
    for(int i = 1,r = 1;i < N;++i,r ^= 1){
        dp[r][0] = (s[i] == 'A'? 0 : 1) + min(dp[r ^ 1][0],dp[r ^ 1][1]);
        dp[r][1] = (s[i] == 'B'? 0 : 1) + min(dp[r ^ 1][0] + 2,dp[r ^ 1][1]);
    }
    
    printf("%d\n",min(dp[(N - 1) & 1][0],dp[(N - 1) & 1][1]));
    
    return 0;
}
