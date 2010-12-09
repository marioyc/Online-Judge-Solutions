#include <cstdio>
#include <algorithm>

using namespace std;

int x[1000000];

int main(){
    int T,L,n;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&L,&n);
        
        for(int i = 0;i<n;++i)
            scanf("%d",&x[i]);
        
        sort(x,x+n);
        
        int ans = L;
        
        for(int i = -1;i<n;++i)
            ans = min(ans,max(i>=0? x[i] : 0,i+1<n? L-x[i+1] : 0));
        
        printf("%d ",ans);
        
        ans = max(L-x[0],x[n-1]);
        printf("%d\n",ans);
    }
    
    return 0;
}
