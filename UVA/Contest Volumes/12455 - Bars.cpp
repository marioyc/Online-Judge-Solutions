#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int T,L,N;
    bool dp[1001];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&L,&N);
        
        memset(dp,0,sizeof dp);
        dp[0] = 1;
        
        for(int i = 0,x;i < N;++i){
            scanf("%d",&x);
            
            for(int j = 1000 - x;j >= 0;--j)
                dp[j + x] |= dp[j];
        }
        
        puts(dp[L]? "YES" : "NO");
    }
    
    return 0;
}
