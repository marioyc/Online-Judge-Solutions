#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N,sum,mn,mx;
    
    while(true){
        scanf("%d",&N);
        
        if(N == 0) break;
        
        sum = 0;
        mn = 1000;
        mx = 0;
        
        for(int i = 0,a;i < N;++i){
            scanf("%d",&a);
            
            sum += a;
            mn = min(mn,a);
            mx = max(mx,a);
        }
        
        printf("%d\n",(sum - mn - mx) / (N - 2));
    }
    
    return 0;
}
