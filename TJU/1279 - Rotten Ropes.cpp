#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int t,n,ans;
    int c[1000];
    
    scanf("%d",&t);
    
    for(int caso=1;caso<=t;caso++){
        scanf("%d",&n);
        
        for(int i=0;i<n;i++) scanf("%d",&c[i]);
        
        sort(c,c+n);
        
        ans=-1;
        
        for(int i=n-1;i>=0;i--)
            ans=max(ans,c[i]*(n-i));
        
        printf("%d\n",ans);
    }
    
    return 0;
}
