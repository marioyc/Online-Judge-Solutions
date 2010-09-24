#include <cstdio>
#include <algorithm>

using namespace std;

struct gangster{
    int T,P,S;
    
    gangster(){
    }
    
    bool operator < (gangster X) const{
        return T>X.T;
    }
};

int main(){    
    int n,k,t;
    
    scanf("%d %d %d",&n,&k,&t);
    
    gangster A[n];
    
    for(int i=0;i<n;i++) scanf("%d",&A[i].T);
    for(int i=0;i<n;i++) scanf("%d",&A[i].P);
    for(int i=0;i<n;i++) scanf("%d",&A[i].S);
    
    sort(A,A+n);
    
    int dp[2][k+1];
    
    for(int i=0;i<=k;i++) dp[(t+1)%2][i]=0;
    
    int aux,pos=0,a;
    
    for(int i=t;i>=0;i--){
        for(int j=0;j<=k;j++){
            dp[i%2][j]=dp[1-i%2][j];
            if(j<k) dp[i%2][j]=max(dp[i%2][j],dp[1-i%2][j+1]);
            if(j>0) dp[i%2][j]=max(dp[i%2][j],dp[1-i%2][j-1]);  
            
            if(pos<n && A[pos].T==i){
                aux=0;                
                for(a=pos;a<n && A[a].T==i;a++) if(A[a].S==j) aux+=A[a].P;                
                dp[i%2][j]+=aux;
            }
        }        
        for(;pos<n && A[pos].T==i;pos++) ;
    }
    
    printf("%d\n",dp[0][0]);
    
    return 0;
}
