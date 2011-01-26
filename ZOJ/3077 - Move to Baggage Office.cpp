#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct baggage{
    int v,a,b;
    
    baggage(){}
    
    baggage(int _v, int _a, int _b){
        v = _v; a = _a; b = _b;
    }
    
    bool operator < (baggage X)const{
        return b<X.b;
    }
}L[100];

int main(){
    int T,s,n,dp[1001];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&s,&n);
        
        for(int i = 0;i<n;++i)
            scanf("%d %d %d",&L[i].v,&L[i].a,&L[i].b);
        
        sort(L,L+n);
        memset(dp,0,sizeof(dp));
        int ans = 0;
        
        for(int i = 0;i<n;++i) for(int j = s;j>=L[i].a;--j){
            dp[j] = max(dp[j],L[i].v+dp[j-L[i].a+L[i].b]);
            if(dp[j]>ans) ans = dp[j];
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
