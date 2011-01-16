#include <cstdio>

using namespace std;

int main(){
    int T,N,H[10000],W[10000];
    int dp[10000],A,B;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc<=T;++tc){
        scanf("%d",&N);
        
        for(int i = 0;i<N;++i) scanf("%d",&H[i]);
        for(int i = 0;i<N;++i) scanf("%d",&W[i]);
        
        int best = 0;
        
        for(int i = 0;i<N;++i){
            dp[i] = W[i];
            
            for(int j = 0;j<i;++j){
                if(H[j]<H[i] && W[i]+dp[j]>dp[i]){
                    dp[i] = W[i]+dp[j];
                }
            }
            
            if(dp[i]>dp[best]) best = i;
        }
        
        A = dp[best];
        
        best = 0;
        
        for(int i = 0;i<N;++i){
            dp[i] = W[i];
            
            for(int j = 0;j<i;++j){
                if(H[j]>H[i] && W[i]+dp[j]>dp[i]){
                    dp[i] = W[i]+dp[j];
                }
            }
            
            if(dp[i]>dp[best]) best = i;
        }
        
        B = dp[best];
        
        if(A>=B) printf("Case %d. Increasing (%d). Decreasing (%d).\n",tc,A,B);
        else printf("Case %d. Decreasing (%d). Increasing (%d).\n",tc,B,A);
    }
    
    return 0;
}
