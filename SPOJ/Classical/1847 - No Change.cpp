#include <cstdio>

using namespace std;

int main(){    
    int x,k;    
    scanf("%d %d",&x,&k);
    
    int a[k];    
    for(int i=0;i<k;i++) scanf("%d",&a[i]);
    
    int S[k];    
    S[k-1]=a[0];
    for(int i=k-2;i>=0;i--) S[i]=S[i+1]+a[k-1-i];
    
    bool dp[2][x+1];
    
    dp[1][0]=true;
    for(int i=1;i<=x;i++) dp[1][i]=false;
    
    for(int i=0;i<k;i++){
        for(int j=0;j<=x;j++){
            dp[i&1][j]=dp[(i&1)^1][j];
            if(j>=S[i]) dp[i&1][j]|=dp[i&1][j-S[i]];
        }
    }
    
    if(dp[(k-1) & 1][x]) printf("YES\n");
    else printf("NO\n");
    
    return 0;
}
