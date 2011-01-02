#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int T,N;
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        long long ans = 0;
        double R = sqrt(N);
        int r = (int)floor(R);
        
        if(r*r==N) ans += r;
        
        for(int i = 1;i<R;++i){
            ans += N/i;
            ans += max(0,N/i-r);
        }
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
