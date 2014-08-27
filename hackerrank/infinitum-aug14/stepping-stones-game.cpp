#include <cstdio>

using namespace std;

int main(){
    int T;
    long long N;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%lld",&N);
        
        int lo = 1,hi = 1000000000,mi;
        
        while(lo < hi){
            mi = (lo + hi) >> 1;
            
            if((long long)mi * (mi + 1) < 2 * N) lo = mi + 1;
            else hi = mi;
        }
        
        if((long long)lo * (lo + 1) == 2 * N) printf("Go On Bob %d\n",lo);
        else printf("Better Luck Next Time\n");
    }
    
    return 0;
}
