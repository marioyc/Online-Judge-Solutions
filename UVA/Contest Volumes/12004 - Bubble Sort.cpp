#include <cstdio>

using namespace std;

int main(){
    int T,n;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d",&n);
        
        long long ans = (long long)n * (n-1);
        
        printf("Case %d: ",tc);
        
        if(ans % 4 == 0) printf("%lld\n",ans / 4);
        else printf("%lld/2\n",ans / 2);
    }
    
    return 0;
}
