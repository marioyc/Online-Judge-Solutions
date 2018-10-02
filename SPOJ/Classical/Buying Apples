#include <iostream>
#include <limits.h>
using namespace std;
 
int main() {
	int t;
	cin>>t;
	while(t--){
        int n,k,i,j;
        cin>>n>>k;
        int a[k];
        for(i=0;i<k;i++)cin>>a[i];
        pair<int,int> dp[k+1][k+1];
        for(i=0;i<=k;i++){
            dp[0][i]={-1,0}; dp[i][0]={0,0};
        }
        for(i=1;i<=k;i++){
            for(j=1;j<=k;j++){
                if( j<i || a[i-1]==-1 )dp[i][j]=dp[i-1][j];
                else{
                    int p = ( (dp[i-1][j].first ==-1)?INT_MAX:dp[i-1][j].first );
                    int q = ( (dp[i][j-i].first ==-1)?INT_MAX:(dp[i][j-i].first+a[i-1]) );
 
                    if( dp[i][j-i].second+1>n )q=INT_MAX;
                    if(p==q &&p!=INT_MAX ){
                        if(dp[i-1][j].second < dp[i][j-1].second+1 ){
                            dp[i][j]=dp[i-1][j];
                        }else dp[i][j]={q,dp[i][j-i].second+1} ;
                    }
                    else if(q<p){
                        dp[i][j]={q,dp[i][j-i].second+1} ;
                    }else dp[i][j]=dp[i-1][j];
 
                    if(dp[i][j].first==INT_MAX){
                        dp[i][j]={-1,0};
                    }
                }
            }
        }
        cout<<dp[k][k].first<<"\n";

	}
 
	return 0;
}
