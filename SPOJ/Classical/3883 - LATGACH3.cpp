#include <cstdio>

using namespace std;

int main(){
    int dp[16];
    
    dp[0] = 1; dp[1] = 3;
    for(int i = 2;i <= 15;++i) dp[i] = 4 * dp[i-1] - dp[i-2];
    
    int n;
    
    while(true){
        scanf("%d",&n);
        if(n == -1) break;
        
        if(n & 1) puts("0");
        else printf("%d\n",dp[n >> 1]);
    }
    
    return 0;
}
