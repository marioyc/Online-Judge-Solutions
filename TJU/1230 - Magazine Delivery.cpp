#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int main(){
    int T,N,adj[30][30],dp[30][30][30];
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        int adj[31][31];
        for(int i = 0;i<N;++i) adj[i][i] = 0;
        
        for(int i = 0;i<N;++i){
            for(int j = i+1;j<N;++j){
                scanf("%d",&adj[i][j]);
                adj[j][i] = adj[i][j];
            }
        }
        
        int ans = -1;
        memset(dp,-1,sizeof(dp));
        dp[0][0][0] = 0;
        
        for(int i = 0;i<N;++i){
            for(int j = 0;j<N;++j){
                for(int k = 0;k<N;++k){
                    if(i>=j && i>=k){
                        for(int x = 0;x<i;++x){
                            if(dp[x][j][k]==-1) continue;
                            int tmp = dp[x][j][k]+adj[x][i];
                            if((i==j+1 || i==k+1 || i==x+1) && (dp[i][j][k]==-1 || tmp<dp[i][j][k]))
                                dp[i][j][k] = tmp;
                        }
                    }else if(j>=i && j>=k){
                        for(int x = 0;x<j;++x){
                            if(dp[i][x][k]==-1) continue;
                            int tmp = dp[i][x][k]+adj[x][j];
                            if((j==i+1 || j==k+1 || j==x+1) && (dp[i][j][k]==-1 || tmp<dp[i][j][k]))
                                dp[i][j][k] = tmp;
                        }
                    }else{
                        for(int x = 0;x<k;++x){
                            if(dp[i][j][x]==-1) continue;
                            int tmp = dp[i][j][x]+adj[x][k];
                            if((k==i+1 || k==j+1 || k==x+1) && (dp[i][j][k]==-1 || tmp<dp[i][j][k]))
                                dp[i][j][k] = tmp;
                        }
                    }
                    
                    if((i==N-1 || j==N-1 || k==N-1) && dp[i][j][k]!=-1 && (ans==-1 || dp[i][j][k]<ans))
                        ans = dp[i][j][k];
                }
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
