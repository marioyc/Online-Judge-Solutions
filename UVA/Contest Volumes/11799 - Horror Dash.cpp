#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T,N,ans;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d",&N);
        ans = 0;
        
        for(int i = 0,x;i < N;++i){
            scanf("%d",&x);
            ans = max(ans,x);
        }
        
        printf("Case %d: %d\n",tc,ans);
    }
    
    return 0;
}
