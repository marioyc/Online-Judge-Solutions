#include <cstdio>
#include <cstring>

using namespace std;

double dp[1000][1001],r;

int main(){
    int N,M,K[1000],P[1000],Q[1000];
    scanf("%d %d",&N,&M);
    
    for(int i = 0;i < N;++i)
        scanf("%d %d %d",&K[i],&P[i],&Q[i]);
    
    for(int i = 0;i < N;++i)
        for(int j = 0;j <= M;++j)
            dp[i][j] = -1;
    
    dp[0][0] = 0;
    if(K[0] > 1) r = (Q[0] - P[0]) * 1.0 / (K[0] - 1);
    else r = 0;
    
    for(int i = 1;i <= M && i <= K[0];++i)
        dp[0][i] = i * P[0] + r * (i * (i-1) / 2);
    
    for(int i = 1;i < N;++i){
        if(K[i] > 1) r = (Q[i] - P[i]) * 1.0 / (K[i] - 1);
        else r = 0;
        
        for(int j = 0;j <= M;++j){
            for(int k = 0;k <= K[i] && j + k <= M;++k){
                if(dp[i-1][j] > -0.5){
                    double cost = dp[i-1][j];
                    if(k > 0) cost += k * P[i] + r * (k * (k-1) / 2);
                    if(dp[i][j + k] < -0.5 || dp[i][j + k] > cost) dp[i][j + k] = cost;
                }
            }
        }
    }
    
    int maxProd = M;
    while(maxProd > 0 && dp[N-1][maxProd] < -0.5) --maxProd;
    
    if(maxProd < M) printf("Maximum possible amount: %d\n",maxProd);
    printf("Minimum possible cost: %.2f\n",dp[N-1][maxProd]);
    
    return 0;
}
