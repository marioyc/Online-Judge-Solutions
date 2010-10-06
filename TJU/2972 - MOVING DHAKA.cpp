#include <cstdio>
#include <algorithm>

using namespace std;

int x[1000000];

int main(){
    int N,T;
    scanf("%d",&T);
    
    for(int tc = 1;tc<=T;++tc){
        scanf("%d",&N);
        
        for(int i = 0;i<N;++i)
            scanf("%d",&x[i]);
        
        sort(x,x+N);
        
        int pos = N/2;
        long long ans = 0;
        
        for(int i = 0;i<=pos;++i) ans += (long long)x[pos]-x[i];
        for(int i = pos;i<N;++i) ans += (long long)x[i]-x[pos];
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
