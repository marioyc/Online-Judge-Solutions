#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int dp[501][501];
    int attraction[500][500];
    int m,n,ans;
    
    while(1){
        scanf("%d %d",&m,&n);
        if(m==0 && n==0) break;
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++) scanf("%d",&attraction[i][j]);
        
        for(int i=m-1;i>=0;i--){
            for(int j=0;j<n-m+i+1;j++){
                if(i==m-1){
                    dp[i][j]=attraction[i][j];
                    continue;
                }
                
                dp[i][j]=-2000000001;
                
                for(int k=j+1;k<n-m+i+2;k++)
                    dp[i][j]=max(dp[i][j],dp[i+1][k]);
                
                dp[i][j]+=attraction[i][j];                
            }
        }
        
        ans=-2000000001;
        
        for(int i=0;i<n-m+1;i++) ans=max(ans,dp[0][i]);
        
        printf("%d\n",ans);
    }
    
    return 0;
}
