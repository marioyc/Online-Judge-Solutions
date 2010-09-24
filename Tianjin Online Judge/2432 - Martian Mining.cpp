#include <cstdio>
#include <algorithm>

using namespace std;

int n,m,P1[500][500],P2[500][500],FR[501][501],FC[501][501],dp[501][501];

int main(){
    while(1){
        scanf("%d %d",&n,&m);
        if(n==0) break;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&P1[i][j]);
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&P2[i][j]);
        
        for(int i=0;i<=m;i++) FR[i][0]=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                FR[i][j]=FR[i][j-1]+P1[i-1][j-1];
        
        for(int i=0;i<=n;i++) FC[0][i]=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                FC[i][j]=FC[i-1][j]+P2[i-1][j-1];
        
        for(int i=0;i<=m;i++) FC[0][i]=0;
        for(int i=0;i<=n;i++) FR[i][0]=0;
        
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                dp[i][j]=max(dp[i-1][j]+FR[i][j],dp[i][j-1]+FC[i][j]);
        
        printf("%d\n",dp[n][m]);
    }
    
    return 0;
}
