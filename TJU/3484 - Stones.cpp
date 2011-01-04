#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T,N,a[100000];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        for(int i = 0;i<N;++i) scanf("%d",&a[i]);
        sort(a,a+N);
        
        int ans = 0;
        for(int i = 0;i+1<N;++i) ans += a[i];
        printf("%d\n",ans);
    }
    
    return 0;
}
