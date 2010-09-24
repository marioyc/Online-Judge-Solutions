#include<cstdio>

using namespace std;

int main(){    
    int n,m;
    int a[10];
    bool dp[1000001];
    
    while(scanf("%d %d",&n,&m)==2){
        for(int i=0;i<m;i++) scanf("%d",&a[i]);
        
        dp[0]=false;
        for(int i=1;i<=n;i++){
            dp[i]=false;
            
            for(int j=0;j<m;j++)
                if(i>=a[j] && !dp[i-a[j]]){
                    dp[i]=true;
                    break;
                }
        }
        
        if(dp[n]) printf("Stan wins\n");
        else printf("Ollie wins\n");
    }
    
    return 0;
}
