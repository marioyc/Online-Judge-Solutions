#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1000000

int dp[MAXN][2];
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
    
    for(int i = 1;i < N;++i){
        dp[i][0] = (s[i] == 'A'? 0 : 1) + min(dp[i - 1][0],dp[i - 1][1]);
        dp[i][1] = (s[i] == 'B'? 0 : 1) + min(dp[i - 1][0] + 2,dp[i - 1][1]);
    }
    
    printf("%d\n",min(dp[N - 1][0],dp[N - 1][1]));
    
    return 0;
}
