#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T,E,F,N,P[500],W[500],dp[10001];
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d %d %d",&E,&F,&N);
        
        for(int i=0;i<N;i++) scanf("%d %d",&P[i],&W[i]);
        
        F-=E;
        fill(dp,dp+F+1,-1);
        
        dp[0]=0;
        for(int i=1;i<=F;i++){
            for(int j=0;j<N;j++){
                if(i<W[j] || dp[i-W[j]]==-1) continue;
                if(dp[i]==-1) dp[i]=P[j]+dp[i-W[j]];
                else dp[i]<?=P[j]+dp[i-W[j]];
            }
        }
        
        if(dp[F]==-1) printf("This is impossible.\n");
        else printf("The minimum amount of money in the piggy-bank is %d.\n",dp[F]);
    }
    
    return 0;
}
