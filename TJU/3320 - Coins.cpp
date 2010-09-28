#include <cstdio>
#include <algorithm>

using namespace std;

bool dp[100001];
int cont[100001];

int main(){
    int n,m,ans;
    
    int A[100],C[100];
    
    while(1){
        scanf("%d %d",&n,&m);
        if(n==0) break;
        
        for(int i=0;i<n;i++) scanf("%d",&A[i]);
        for(int i=0;i<n;i++) scanf("%d",&C[i]);
        
        for(int i=0;i<=m;i++) dp[i]=false;
        dp[0]=true; ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<=m;j++) cont[j]=0;
            
            for(int j=0;j+A[i]<=m;j++){
                if(dp[j] && !dp[j+A[i]] && cont[j]<C[i]){
                    cont[j+A[i]]=cont[j]+1;
                    dp[j+A[i]]=true;
                    ans++;
                }
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
