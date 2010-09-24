#include<cstdio>
#include<algorithm>

using namespace std;

int main(){    
    int M[100][100];
    int N,ans;
    int sum[100][101];
    int dp[101];
    
    while(scanf("%d",&N)==1){
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++) scanf("%d",&M[i][j]);
        
        for(int i=0;i<N;i++){
            sum[i][0]=0;
            for(int j=1;j<=N;j++) sum[i][j]=sum[i][j-1]+M[i][j-1];
        }
        
        ans=-(1<<30);
        
        for(int i=0;i<N;i++){
            for(int j=i;j<N;j++){
                dp[0]=0;
                for(int k=0;k<N;k++){
                    dp[k+1]=max(sum[k][j+1]-sum[k][i]+dp[k],sum[k][j+1]-sum[k][i]);
                    ans=max(ans,dp[k+1]);
                }
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
