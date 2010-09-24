#include<cstdio>
#include<algorithm>
 
using namespace std; 

int main(){
    int N;

    scanf("%d",&N);

    int a[N];

    for(int i=0;i<N;i++) scanf("%d",&a[i]);

    sort(a,a+N);

    int dp[N],next[N];

    int ans=0;

    for(int i=N-1;i>=0;i--){
        dp[i]=1;

        for(int j=i+1;j<N;j++)
            if(a[j]%a[i]==0 && 1+dp[j]>dp[i]){
                dp[i]=1+dp[j];
                next[i]=j;
            }
        
        ans=max(ans,dp[i]);
    }

    printf("%d\n",ans);

    int pos;

    for(int i=0;i<ans;i++)
        if(dp[i]==ans){
            pos=i;
            break;
        }

    for(int i=0;i<ans;i++){
        printf("%d",a[pos]);
        pos=next[pos];
        if(i!=ans-1) printf(" ");
        else printf("\n");
    }

    return 0;
}
