#include <cstdio>

using namespace std;

int main(){
    int N;    
    scanf("%d",&N);
    
    int a[N];
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    
    int dp[N];
    int ans=0;
    
    for(int i=N-1;i>=0;i--){
        dp[i]=1;
        
        for(int j=i+1;j<N;j++)
            if(a[i]<a[j] && dp[i]<dp[j]+1) dp[i]=dp[j]+1;
        
        if(ans<dp[i]) ans=dp[i];
    }
    
    printf("%d\n",ans);
    
    return 0;
}
