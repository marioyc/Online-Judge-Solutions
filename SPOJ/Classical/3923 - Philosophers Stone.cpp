#include <cstdio>

using namespace std;

#define max(a,b) a>b? a:b

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int T,R,C,ans;
    int M[100][100];
    int dp[2][100];
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d %d",&R,&C);
        
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                scanf("%d",&M[i][j]);
        
        for(int i=0;i<C;i++) dp[(R-1)&1][i]=M[R-1][i];
        
        for(int i=R-2;i>=0;i--)
            for(int j=0;j<C;j++){
                dp[i&1][j]=dp[1-i&1][j];
                if(j>0) dp[i&1][j]=max(dp[i&1][j],dp[1-i&1][j-1]);
                if(j+1<C) dp[i&1][j]=max(dp[i&1][j],dp[1-i&1][j+1]);
                dp[i&1][j]+=M[i][j];
            }
        
        ans=0;
        for(int i=0;i<C;i++) ans=max(ans,dp[0][i]);
        
        printf("%d\n",ans);
    }
    
    return 0;
}
