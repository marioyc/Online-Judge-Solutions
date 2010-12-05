#include <cstdio>
#include <algorithm>

using namespace std;

/*
F(1,1) = 1
F(2,2) = 3
x>1 : F(x,x) = F(x-1,x)+F(x-1,x-1)+1 = 2*F(x-1,x-1)+1

F(x,x) = 2*F(x-1,x-1)+1
F(x-1,x-1) = 2*F(x-2,x-2)+1
...
F(1,1) = 1

-> F(x,x) = 2^0+2^1+...+2^(x-1) = 2^x-1
-> F(10,10)>1000
*/

int dp[1001][1001];

int main(){    
    for(int i = 0;i<=1000;++i){
        for(int j = 0;j<=1000;++j){
            if(i>=10 && j>=10) dp[i][j] = 1000;
            else if(i==0 || j==0) dp[i][j] = 0;
            else if(j==1) dp[i][j] = i;
            else if(i<j) dp[i][j] = dp[i][i];
            else dp[i][j] = min(1000,dp[i-1][j-1]+dp[i-1][j]+1);
        }
    }    
    
    int F,E;
    
    while(true){
        scanf("%d %d",&E,&F);
        if(F==0 || E==0) break;
        
        int lo = 1,hi = F,mi;
        
        while(lo<hi){
            mi = (lo+hi)>>1;
            
            if(F<=dp[mi][E]) hi = mi;
            else lo = mi+1;
        }
        
        printf("%d\n",lo);
    }
    
    return 0;
}
