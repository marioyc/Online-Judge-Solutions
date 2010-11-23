#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int M,N;
    scanf("%d %d",&M,&N);
    
    long long dp[100][500],aux1[500],aux2[500],INF = 1000000001;
    int choose[100][500],choose1[500],choose2[500],cost[500];
    
    for(int i = 0;i<N;++i) scanf("%lld",&dp[0][i]);
    
    for(int i = 1;i<M;++i){
        for(int j = 0;j<N;++j) scanf("%d",&cost[j]);
        
        aux1[0] = cost[0]+dp[i-1][0];
        choose1[0] = 0;
        
        for(int j = 1;j<N;++j){
            aux1[j] = min(INF,cost[j]+min(dp[i-1][j],aux1[j-1]));
            choose1[j] = (dp[i-1][j]<=aux1[j-1]? 0 : -1);
        }
        
        aux2[N-1] = cost[N-1]+dp[i-1][N-1];
        choose2[N-1] = 0;
        
        for(int j = N-2;j>=0;--j){
            aux2[j] = min(INF,cost[j]+min(dp[i-1][j],aux2[j+1]));
            choose2[j] = (dp[i-1][j]<=aux2[j+1]? 0 : 1);
        }
        
        for(int j = 0;j<N;++j){
            dp[i][j] = min(aux1[j],aux2[j]);
            choose[i][j] = (aux1[j]<=aux2[j]? choose1[j] : choose2[j]);
        }
    }
    
    int best = INF,s = -1;
    
    for(int i = 0;i<N;++i){
        if(dp[M-1][i]<best){
            best = dp[M-1][i];
            s = i;
        }
    }
    
    int r = M-1,c = s,x,ans[50000],len = 0;
    ans[len] = c; ++len;
    
    while(r!=0){
        x = choose[r][c];
        if(x==0) --r;
        else c += x;
        ans[len] = c; ++len;
    }
    
    for(int i = len-1;i>=0;--i)
        printf("%d ",ans[i]+1);
    putchar('\n');
    
    return 0;
}
