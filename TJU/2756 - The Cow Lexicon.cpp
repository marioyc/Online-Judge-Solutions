#include <cstdio>
#include <cstring>

using namespace std;

#define min(a,b) a<b? a:b

int W,L;

char txt[301];
char w[600][26];
int dp[301];

int count(int n, int ind){
    int cont=0;
    int pos=n-1;
    
    for(int i=strlen(w[ind])-1;i>=0;i--){
        while(txt[pos] != w[ind][i]){
            pos--;
            cont++;
            
            if(pos<0) return n;
        }
        pos--;
    }
    
    return cont+dp[pos+1];
}

int main(){    
    scanf("%d %d",&W,&L);
    
    scanf("%s",txt);
    
    for(int i=0;i<W;i++) scanf("%s",w[i]);
    
    dp[0]=0;
    
    for(int i=1;i<=L;i++){
        dp[i]=i;
        
        for(int j=0;j<W;j++) dp[i]=min(dp[i],count(i,j));
    }
    
    printf("%d\n",dp[L]);
    
    return 0;
}
