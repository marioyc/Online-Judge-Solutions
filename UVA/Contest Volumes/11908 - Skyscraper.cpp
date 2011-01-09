#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> L[100001];
int B[30000],C[30000],dp[100002];

int main(){
    int tc = 1,T,N;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        for(int i = 0;i<=100000;++i) L[i].clear();
        
        for(int i = 0,A;i<N;++i){
            scanf("%d %d %d",&A,&B[i],&C[i]);
            L[A].push_back(i);
        }
        
        dp[100001] = 0;
        
        for(int i = 100000;i>=0;--i){
            dp[i] = dp[i+1];
            
            for(int j = L[i].size()-1,k;j>=0;--j){
                k = L[i][j];
                dp[i] = max(dp[i],C[k]+(i+B[k]<=100000? dp[i+B[k]] : 0));
            }
        }
        
        printf("Case %d: %d\n",tc++,dp[0]);
    }
    
    return 0;
}
