/*
ID:zion_ba1
LANG:C++
TASK:diet
*/

#include <iostream>

using namespace std;

int main(){
    freopen("diet.in","r",stdin);
    freopen("diet.out","w",stdout);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    int H,N; scanf("%d %d",&H,&N);
    
    int W[N];
    for(int i=0;i<N;i++) scanf("%d",&W[i]);
    
    int dp[2][H+1];
    for(int i=0;i<=H;i++) dp[0][i]=0;
    
    for(int i=1;i<=N;i++)
        for(int j=0;j<=H;j++){
            if(j>=W[i-1]) dp[i&1][j]=max(dp[(i-1)&1][j],W[i-1]+dp[(i-1)&1][j-W[i-1]]);
            else dp[i&1][j]=dp[(i-1)&1][j];
        }
    
    printf("%d\n",dp[N&1][H]);
    
    return 0;
}
