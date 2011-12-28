#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    long long N,ans = 1,lo,hi,mi;
    
    scanf("%lld",&N);
    
    for(long long i = 1;i * i * i <= N;++i){
        if(N % i == 0){
            if(N / i % i == 0) ans = max(ans,i * i);
            
            long long N2 = N / i;
            
            lo = 1; hi = 1000000000;
            
            while(lo < hi){
                mi = (lo + hi) >> 1;
                
                if(mi * mi < N2) lo = mi + 1;
                else hi = mi;
            }
            
            if(lo * lo == N2) ans = max(ans,N2);
        }
    }
    
    printf("%lld\n",ans);
    
    return 0;
}
