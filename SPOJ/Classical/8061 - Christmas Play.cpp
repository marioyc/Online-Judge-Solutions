#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T,N,K,h[20000];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&N,&K);
        
        for(int i = 0;i < N;++i) scanf("%d",&h[i]);
        sort(h,h + N);
        
        int ans = h[K - 1] - h[0];
        
        for(int i = 1;i + K - 1 < N;++i)
            ans = min(ans,h[i + K - 1] - h[i]);
        
        printf("%d\n",ans);
    }
    
    return 0;
}
