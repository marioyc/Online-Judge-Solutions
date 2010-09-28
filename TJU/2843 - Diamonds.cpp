#include<cstdio>
#include<algorithm>

using namespace std;

int main(){    
    int t,n,aux;
    int cost[10000][3];
    int dp[2][3];
    
    scanf("%d",&t);
    
    for(int i=0;i<t;i++){
        scanf("%d",&n);
        
        for(int j=0;j<n;j++) scanf("%d %d %d",&cost[j][0],&cost[j][1],&cost[j][2]);
        
        for(int j=0;j<3;j++) dp[0][j]=cost[0][j];
        
        for(int j=1;j<n;j++)
            for(int k=0;k<3;k++) dp[j][k]=cost[j][k]+max(dp[j-1][(k+1)%3],dp[j-1][(k+2)%3]);
                
        printf("%d\n",max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2])));
    }
    
    return 0;
}
