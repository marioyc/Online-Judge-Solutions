#include<cstdio>
#include<algorithm>

using namespace std;

int main(){    
    int N,K;
    
    scanf("%d %d",&N,&K);
    
    int S[N];
    long long dp[(1<<N)][N];    
    int m=(1<<N);
    
    for(int i=0;i<N;i++) scanf("%d",&S[i]);
    
    for(int mask=1;mask<m;mask++){
        if(__builtin_popcount(mask)==1){
            for(int i=0;i<N;i++)
                if(mask & (1<<i)) dp[mask][i]=1;
                else dp[mask][i]=0;
            
            continue;
        }
        
        for(int i=0;i<N;i++){
            dp[mask][i]=0;
            
            if((mask & (1<<i))==0) continue;
            
            for(int j=0;j<N;j++) if((mask & (1<<j)) && abs(S[i]-S[j])>K) dp[mask][i]+=dp[mask & (~(1<<i))][j];
        }
    }
    
    long long tot=0;
    
    for(int i=0;i<N;i++) tot+=dp[(1<<N)-1][i];
    
    printf("%lld\n",tot);
    
    return 0;
}
