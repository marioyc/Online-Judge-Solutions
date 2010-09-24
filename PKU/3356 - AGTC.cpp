#include <cstdio>
#include <algorithm>

using namespace std;

int dp[1001][1001];

int main(){
    int n,m;
    char s1[1001],s2[1001];
    
    for(int i=0;i<=1000;i++) dp[0][i]=i;
    for(int i=0;i<=1000;i++) dp[i][0]=i;
    
    while(scanf("%d %s %d %s",&n,s1,&m,s2)==4){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                dp[i][j]=min(min(dp[i-1][j]+1,dp[i][j-1]+1),dp[i-1][j-1]+(s1[i-1]!=s2[j-1]));
        
        printf("%d\n",dp[n][m]);
    }
    
    return 0;
}
