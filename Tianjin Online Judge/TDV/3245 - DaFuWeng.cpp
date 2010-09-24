#include <cstdio>
#include <algorithm>

using namespace std;

int main(){   
    int T,N,M;
    int a[100001];
    double dp[100001],p;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d %d",&M,&N);
        
        for(int i=1;i<=M;i++) scanf("%d",&a[i]);
        
        fill(dp,dp+M+1,0.0);
        p=1.0/N;
        
        for(int i=0;i<=M;i++){
            if(i+N>M) p=1.0/(M-i+1);
            
            for(int j=1;j<=N && i+j<=M;j++) dp[i+j]+=p*(dp[i]+a[i+j]);
        }
        
        printf("%.1f\n",dp[M]);
    }
    
    return 0;
}
