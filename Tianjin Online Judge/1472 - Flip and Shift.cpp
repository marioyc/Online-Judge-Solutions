#include <cstdio>

using namespace std;

int main(){
    int T,n,x,diff;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;++tc){
        scanf("%d",&n);
        
        diff = 0;
        
        for(int i=0;i<n;++i){
            scanf("%d",&x);
            if(x==1){
                if(i%2==0) ++diff;
                else --diff;
            }
        }
        
        if(n%2==1 || (diff>=-1 && diff<=1)) printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}
