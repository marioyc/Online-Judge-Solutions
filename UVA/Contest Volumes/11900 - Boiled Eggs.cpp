#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int tc = 1,T,n,P,Q,a[30];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d %d",&n,&P,&Q);
        
        for(int i = 0;i<n;++i) scanf("%d",&a[i]);
        
        int ans = 0;
        
        for(int i = 0,q = 0;i<n;++i){
            if(ans+1<=P && q+a[i]<=Q){
                ++ans;
                q += a[i];
            }else break;
        }
        
        printf("Case %d: %d\n",tc++,ans);
    }
    
    return 0;
}
