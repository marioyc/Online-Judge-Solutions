#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T,c,x,m,mx;
    long long n,ans;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d",&c);
        
        ans=mx=-1;
        
        for(int i=0;i<c;i++){
            n=0;
            
            for(int j=0;j<9;j++){
                scanf("%d",&x);
                n+=x;
            }
            
            scanf("%d",&m);
            mx>?=m;
            
            if(m==n) continue;
            
            if(ans!=-1) ans=__gcd(ans,(m>n? m-n:n-m));
            else ans=(m>n? m-n:n-m);
        }
        
        if(ans>=2 && mx<ans) printf("%d\n",ans);
        else printf("impossible\n");
    }
    
    return 0;
}
