#include <cstdio>
#define max(a,b) a>b? a:b

using namespace std;

int main(){
    int M,N,T,ans;
    
    while(1){
        scanf("%d %d",&M,&N);
        if(M==0) break;
        
        int C[N],dp[max(M,N)+1],R[M];
        
        dp[0]=0;
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++) scanf("%d",&C[j]);
            
            dp[1]=C[0];
            for(int j=2;j<=N;j++) dp[j]=max(dp[j-1],dp[j-2]+C[j-1]);
            R[i]=max(dp[N],dp[N-1]);
        }
        
        dp[1]=R[0];
        for(int i=2;i<=M;i++) dp[i]=max(dp[i-1],dp[i-2]+R[i-1]);
        
        ans=max(dp[M],dp[M-1]);
        
        printf("%d\n",ans);
    }
    
    return 0;
}
