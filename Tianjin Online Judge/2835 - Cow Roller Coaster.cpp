#include<cstdio>
#include<algorithm>

using namespace std;

struct component{
    int X,W,F,C;
    
    component(){
    }
    
    bool operator < (component P) const{
        return X<P.X;
    }
};

int main(){    
    int L,N,B;
    
    scanf("%d %d %d",&L,&N,&B);
    
    component comp[N];
    
    for(int i=0;i<N;i++) scanf("%d %d %d %d",&comp[i].X,&comp[i].W,&comp[i].F,&comp[i].C);
    
    sort(comp,comp+N);
    
    int dp[L+1][B+1];
    
    for(int i=0;i<=L;i++)
        for(int j=0;j<=B;j++) dp[i][j]=-1;
    
    for(int i=0;i<=B;i++) dp[0][i]=0;
    
    for(int i=0;i<N;i++){
        for(int j=comp[i].C;j<=B;j++){
            if(dp[comp[i].X][j]==-1) continue;
            
            dp[comp[i].X+comp[i].W][j-comp[i].C]=max(dp[comp[i].X+comp[i].W][j-comp[i].C],dp[comp[i].X][j]+comp[i].F);
        }
    }
    
    int ans=-1;
    
    for(int i=0;i<=B;i++) ans=max(ans,dp[L][i]);
    
    printf("%d\n",ans);
    
    return 0;
}
