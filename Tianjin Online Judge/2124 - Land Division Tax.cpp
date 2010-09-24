#include<iostream>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int M[2000];
    int dp[200][201];
    int sum[200][201];
    int N,ans;
    float F;
    
    while(1){
        scanf("%d %f",&N,&F);
        if(N==0) break;
        
        for(int i=0;i<N;i++) scanf("%d",&M[i]);
        
        for(int i=0;i<N;i++) sum[i][1]=M[i];
        
        for(int j=2;j<=N;j++)
            for(int i=0;i<N;i++) sum[i][j]=sum[i][1]+sum[(i+1)%N][j-1];
        
        for(int i=0;i<N;i++) dp[i][1]=0;
        
        for(int j=2;j<=N;j++){
            for(int i=0;i<N;i++){
                dp[i][j]=(1<<30);
                for(int k=1;k<j;k++)
                    dp[i][j]=min(dp[i][j],max(sum[i][k],sum[(i+k)%N][j-k])+dp[i][k]+dp[(i+k)%N][j-k]);
            }
        }
        
        ans=dp[0][N];
        
        for(int i=1;i<N;i++) ans=min(ans,dp[i][N]);
        
        printf("%.2f\n",ans*F);
    }
    
    return 0;
}
