#include <cstdio>
#include <cstring>

using namespace std;

int cont[1000000];

int main(){
    int T,d,n;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&d,&n);
        
        memset(cont,0,sizeof cont);
        ++cont[0];
        
        long long ans = 0;
        
        for(int i = 0,x,sum = 0;i < n;++i){
            scanf("%d",&x);
            
            sum = (sum + x) % d;
            
            ans += cont[sum];
            ++cont[sum];
        }
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
