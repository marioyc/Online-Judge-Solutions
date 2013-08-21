#include <cstdio>
#include <algorithm>

using namespace std;

int T,N,a[500000];

int solve(int w){
    int ret = 0;
    
    for(int i = 0;i < N;++i)
        if(i <= ret + 1)
            ret = max(ret,i + min(a[i],w) - 1);
    
    return ret;
}

int main(){
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        for(int i = 0;i < N;++i)
            scanf("%d",&a[i]);
        
        if(a[0] == 0) printf("No solution!\n");
        else{
            int lo = 1,hi = N,mi;
            
            while(lo < hi){
                mi = (lo + hi) >> 1;
                
                if(solve(mi) < N - 1) lo = mi + 1;
                else hi = mi;
            }
            
            if(solve(lo) < N - 1) printf("No solution!\n");
            else printf("%d\n",lo);
        }
    }
    
    return 0;
}
