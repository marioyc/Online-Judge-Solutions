#include<iostream>

using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    long long dp[100][101];
    int a[100];
    int n,k;
    
    long long tot;
    
    while(1){
        cin>>n>>k;
        if(n==0 && k==0) break;
        
        for(int i=0;i<n;i++) cin>>a[i];
        
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<n;i++){
            dp[i][1]=1;
            for(int j=0;j<i;j++){
                if(a[j]>=a[i]) continue;
                for(int x=1;x<k;x++){
                    dp[i][x+1]+=dp[j][x];
                }
            }
        }
        
        tot=0;        
        for(int i=0;i<n;i++) tot+=dp[i][k];
        
        cout<<tot<<endl;
    }
}
