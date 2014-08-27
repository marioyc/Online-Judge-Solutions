#include <cstdio>

using namespace std;

#define MOD 1000000007

int main(){
    int N;
    long long a,ans = 1;
    
    scanf("%d",&N);
    
    for(int i = 0;i < N;++i){
        scanf("%lld",&a);
        
        long long aux = 1,x = 2;
        
        while(a){
            if(a & 1) aux = aux * x % MOD;
            x = x * x % MOD;
            a >>= 1;
        }
        
        ++aux;
        ans = ans * aux % MOD;
    }
    
    --ans;
    if(ans < 0) ans += MOD;
    printf("%lld\n",ans);
    
    return 0;
}
