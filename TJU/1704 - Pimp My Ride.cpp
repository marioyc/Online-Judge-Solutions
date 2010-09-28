#include<cstdio>
#include<algorithm>

using namespace std;

int main(){    
    int T,n;
    int M[14][14];
    int dp[1<<14];
    int N,aux,cost;        
    
    scanf("%d",&T);
    
    for(int caso=1;caso<=T;caso++){
        scanf("%d",&n);
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) scanf("%d",&M[i][j]);
        
        N=(1<<n)-1;
        
        fill(dp,dp+N+1,-1);
        dp[N]=0;
        
        for(int mask=N-1;mask>=0;mask--){
            aux=INT_MAX;
            
            for(int i=0;i<n;i++){
                if((mask & (1<<i))==0){
                    cost=dp[mask | (1<<i)];
                    
                    for(int j=0;j<n;j++)
                        if(j==i || ((mask & (1<<j))!=0)) cost+=M[i][j];
                    
                    aux=cost<aux? cost:aux;
                }
            }
            
            dp[mask]=aux;
        }
        
        printf("Scenario #%d:\nYou have officially been pimped for only $%d\n\n",caso,dp[0]);
    }
    
    return 0;
}
