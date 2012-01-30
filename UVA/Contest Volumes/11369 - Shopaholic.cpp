#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T,N,a[20000];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        for(int i = 0;i < N;++i) scanf("%d",&a[i]);
        sort(a,a + N);
        
        int ans = 0;
        
        for(int i = N - 3;i >= 0;i -= 3)
            ans += a[i];
        
        printf("%d\n",ans);
    }
    
    return 0;
}
