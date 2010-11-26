#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N,M[100][100],S[100][101];
    scanf("%d",&N);
    
    for(int i = 0;i<N;++i)
        for(int j = 0;j<N;++j)
            scanf("%d",&M[i][j]);
    
    for(int i = 0;i<N;++i) S[i][0] = 0;
    
    for(int i = 0;i<N;++i)
        for(int j = 1;j<=N;++j)
            S[i][j] = S[i][j-1]+M[i][j-1];
    
    
    int ans = M[0][0],dp[100];
    
    for(int i = 0;i<N;++i){
        for(int j = i;j<N;++j){
            dp[0] = S[0][j+1]-S[0][i];
            ans = max(ans,dp[0]);
            
            for(int k = 1;k<N;++k){
                int aux = S[k][j+1]-S[k][i];
                dp[k] = aux+max(0,dp[k-1]);
                ans = max(ans,dp[k]);
            }
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}
