#include <cstdio>
#include <algorithm>

using namespace std;

int dp[100000],ans[100000];

int main(){
    dp[0] = 0; ans[0] = 0;
    dp[1] = 1; ans[1] = 1;
    
    for(int i = 2;i<100000;++i){
        if(i&1){
            dp[i] = dp[i/2]+dp[i/2+1];
            ans[i] = max(dp[i],ans[i-1]);
        }else{
            dp[i] = dp[i/2];
            ans[i] = ans[i-1];
        }
    }
    
    int N;
    
    while(true){
        scanf("%d",&N);
        if(N==0) break;
        
        printf("%d\n",ans[N]);
    }
    
    return 0;
}
