#include<cstdio>

using namespace std;

#define min(a,b) a<b? a:b

int dp[2000][2000];

int main(){    
    int N,M;
    char str[2001];
    
    scanf("%d %d %s\n",&N,&M,str);
    
    int cost[26],a,b;
    char c;
    
    for(int i=0;i<N;i++){
        scanf("%c %d %d\n",&c,&a,&b);
        cost[c-'a']=min(a,b);
    }
    
    int s,e;
    
    for(int k=0;k<M;k++){
        for(s=0;s+k<M;s++){
            e=s+k;
            
            if(k==0 || (k==1 && str[s]==str[e])) dp[s][e]=0;
            else{
                dp[s][e]=min(cost[str[s]-'a']+dp[s+1][e],cost[str[e]-'a']+dp[s][e-1]);
                if(str[s]==str[e]) dp[s][e]=min(dp[s][e],dp[s+1][e-1]);
            }
        }
    }
    
    printf("%d\n",dp[0][M-1]);
    
    return 0;
}
