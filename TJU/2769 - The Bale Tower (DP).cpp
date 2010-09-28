#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int N,ans;
    int a1[20];
    int a2[20];
    int dp[20];
    
    scanf("%d",&N);
    
    for(int i=0;i<N;i++) scanf("%d %d",&a1[i],&a2[i]);
    
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(a1[j]>a1[i] && a2[j]>a2[i]){
                swap(a1[i],a1[j]);
                swap(a2[i],a2[j]);
            }
        }
    }
    
    for(int i=0;i<N;i++){
        dp[i]=1;
        
        for(int j=i-1;j>=0;j--)
            if(a1[j]>a1[i] && a2[j]>a2[i]) dp[i]=max(dp[i],1+dp[j]);
    }
    
    ans=-1;
    
    for(int i=0;i<N;i++) ans=max(ans,dp[i]);
    
    printf("%d\n",ans);
    
    return 0;
}
