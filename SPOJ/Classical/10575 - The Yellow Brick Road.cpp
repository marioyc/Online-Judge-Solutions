#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N;
    int x[1000],y[1000],z[1000];
    
    while(scanf("%d",&N) == 1){
        if(N == 0) break;
        for(int i = 0;i < N;++i)
            scanf("%d %d %d",&x[i],&y[i],&z[i]);
        
        int g = x[0];
        
        for(int i = 0;i < N;++i){
            g = __gcd(g,x[i]);
            g = __gcd(g,y[i]);
            g = __gcd(g,z[i]);
        }
        
        long long ans = 0;
        
        for(int i = 0;i < N;++i)
            ans += (long long)(x[i] / g) * (y[i] / g) * (z[i] / g);
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
