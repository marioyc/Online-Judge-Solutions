/*
ID:zion_ba1
LANG:C++
TASK:numtri
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int a[500500],dp[500500];

int main(){
    freopen("numtri.in","r",stdin);
    freopen("numtri.out","w",stdout);
    
    int R,N,n;
    
    scanf("%d",&R);
    N=R*(R+1)/2;
    
    for(int i=0;i<N;i++) scanf("%d",&a[i]);
    
    for(int i=0;i<R;i++) dp[N-1-i]=a[N-1-i];
    
    for(int i=R-2;i>=0;i--){
        n=i*(i+1)/2;
        for(int j=0;j<=i;j++) dp[n+j]=a[n+j]+max(dp[n+j+i+1],dp[n+j+i+2]);
    }
    
    printf("%d\n",dp[0]);
    
    return 0;
}
