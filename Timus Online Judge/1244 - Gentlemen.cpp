#include <cstdio>
#include <cstring>

using namespace std;

int w[100],dp[100001],choice[100001];

int main(){
    int W,N;
    scanf("%d %d",&W,&N);    
    
    W = -W;
    
    for(int i = 0;i<N;++i){
        scanf("%d",&w[i]);
        W += w[i];
    }
    
    memset(dp,0,sizeof(dp));
    memset(choice,0,sizeof(choice));
    
    dp[0] = 1;
    choice[0] = -1;
    
    for(int i = N-1;i>=0;--i){
        for(int j = W;j>=w[i];--j){
            if(dp[j-w[i]]!=0){
                dp[j] += dp[j-w[i]];
                if(dp[j]>2) dp[j] = 2;
                if(choice[j]==0) choice[j] = i+1;
            }
        }
    }
    
    if(dp[W]==2) printf("-1\n");
    else if(dp[W]==0) printf("0\n");
    else{
        while(W!=0){
            printf("%d ",choice[W]);
            W -= w[choice[W]-1];
        }
        
        putchar('\n');
    }
    
    return 0;
}
