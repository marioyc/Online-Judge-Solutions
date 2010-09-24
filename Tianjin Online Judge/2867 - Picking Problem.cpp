#include<cstdio>
#include<algorithm>

using namespace std;

struct game{
    int S,D;
    
    game(){
    }
    
    game(int s, int d){
        S=s;
        D=d;
    }
    
    bool operator < (game X) const{
        if(S!=X.S) return S<X.S;
        return D<X.D;
    }
};

int main(){    
    int N,S,D,ans;
    game M[10000];
    int dp[10000];
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        
        for(int i=0;i<N;i++){
            scanf("%d %d",&S,&D);
            M[i].S=S;
            M[i].D=D;
        }
        
        sort(M,M+N);
        
        dp[0]=1;
        ans=1;
        
        for(int i=1;i<N;i++){
            dp[i]=1;
            for(int j=0;j<i;j++)
                if(M[j].S+M[j].D<=M[i].S) dp[i]=max(dp[i],1+dp[j]);
            ans=max(ans,dp[i]);
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
