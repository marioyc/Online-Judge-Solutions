#include<cstdio>
#include<algorithm>

using namespace std;

short a[1000000];
short b[1000000];
int dp[2][3];

int main(){
    int T,n,x;
    
    scanf("%d",&T);
    
    for(int caso=1;caso<=T;caso++){
        scanf("%d",&n);
        
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0;i<n;i++) scanf("%d",&b[i]);
        
        for(int i=n-1;i>=0;i--){
            x=0;            
            if(i+1<n) x=max(x,dp[0][(i+1)%3]);
            if(i+2<n) x=max(x,dp[1][(i+2)%3]);
            dp[0][i%3]=x+a[i];
            
            x=0;
            if(i+1<n) x=max(x,dp[1][(i+1)%3]);
            if(i+2<n) x=max(x,dp[0][(i+2)%3]);
            dp[1][i%3]=x+b[i];
        }
        
        printf("%d\n",max(dp[0][0],dp[1][0]));
    }
    
    return 0;
}
