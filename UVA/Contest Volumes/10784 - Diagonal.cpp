#include <cstdio>

using namespace std;

int main(){
    int tc = 1;
    long long N;
    
    while(true){
        scanf("%lld",&N);
        if(N == 0) break;
        
        int lo = 4,hi = 100000000,mi;
        
        while(lo < hi){
            mi = (lo + hi) >> 1;
            
            if((long long)mi * (mi - 3) >= N * 2) hi = mi;
            else lo = mi + 1;
        }
        
        printf("Case %d: %d\n",tc++,lo);
    }
    
    return 0;
}
