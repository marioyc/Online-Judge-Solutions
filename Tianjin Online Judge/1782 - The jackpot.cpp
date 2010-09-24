#include <cstdio>

using namespace std;

int main(){    
    int N,a[10000],dp[10000];
    int ans;
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        
        for(int i=0;i<N;i++) scanf("%d",&a[i]);
        
        ans=a[0];
        dp[0]=a[0];
        
        for(int i=1;i<N;i++){
            if(dp[i-1]<0) dp[i]=a[i];
            else dp[i]=dp[i-1]+a[i];
            
            ans>?=dp[i];
        }
        
        if(ans<0) printf("Losing streak.\n");
        else printf("The maximum winning streak is %d.\n",ans);      
    }
    
    return 0;
}
