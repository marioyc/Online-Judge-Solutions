#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n,m,t,dp[10000];
    
    while(scanf("%d %d %d",&n,&m,&t)==3){
        fill(dp,dp+t+1,-1);
        dp[0]=0;
        
        for(int i=1;i<=t;i++){
            if(i>=n && dp[i-n]!=-1) dp[i]=1+dp[i-n];
            if(i>=m && dp[i-m]!=-1) dp[i]>?=1+dp[i-m];
        }
        
        if(dp[t]!=-1) printf("%d\n",dp[t]);
        else{
            for(int i=t;;i--){
                if(dp[i]!=-1){
                    printf("%d %d\n",dp[i],t-i);
                    break;
                }
            }
        }
    }
    
    return 0;
}
