#include <cstdio>

using namespace std;

int main(){
    int N,C;
    
    scanf("%d %d",&N,&C);
    
    int a[C];
    
    for(int i=0;i<C;i++) scanf("%d",&a[i]);
    
    int dp[N+1][C];
    
    for(int i=1;i<=N;i++)
        for(int j=0;j<C;j++)
            dp[i][j]=0;
    
    for(int i=0;i<C;i++) dp[0][i]=1;
    
    for(int i=1;i<=N;i++)
        for(int j=0;j<C;j++)
            if(i>=a[j] && j>0) dp[i][j]=dp[i-a[j]][j]+dp[i][j-1];
            else if(i>=a[0]) dp[i][0]=dp[i-a[0]][0];
            else if(j>0) dp[i][j]=dp[i][j-1];
            else dp[i][0]=0;
    
    printf("%d\n",dp[N][C-1]);
    
    return 0;
}
