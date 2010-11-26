#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N,L[3],C[3];
    
    for(int i = 0;i<3;++i) scanf("%d",&L[i]);
    for(int i = 0;i<3;++i) scanf("%d",&C[i]);
    scanf("%d",&N);
    
    int A,B;
    scanf("%d %d",&A,&B);
    --A; --B;
    
    if(A>B) swap(A,B);
    
    int S[10001];
    S[0] = 0;
    
    for(int i = 1,d;i<N;++i) scanf("%d",&S[i]);
    
    int prev[10001][3],lo,hi,mi;
    
    for(int j = 0;j<3;++j) prev[0][j] = 0;
    
    for(int i = 1;i<N;++i) for(int j = 0;j<3;++j){
        prev[i][j] = i;
        if(S[i]-S[i-1]>L[j]) continue;
        
        lo = 0; hi = i;
        
        while(lo<hi){
            mi = (lo+hi)>>1;
            if(S[i]-S[mi]>L[j]) lo = mi+1;
            else hi = mi;
        }
        
        prev[i][j] = lo;
    }
    
    long long INF = 1000000001,dp[10001];
    
    for(int i = 0;i<=A;++i) dp[i] = 0;
    
    for(int i = A+1;i<=B;++i){
        dp[i] = INF;
        
        for(int j = 0;j<3;++j)
            if(prev[i][j]!=i)
                dp[i] = min(dp[i],dp[prev[i][j]]+C[j]);
    }
    
    printf("%lld\n",dp[B]);
    
    return 0;
}
