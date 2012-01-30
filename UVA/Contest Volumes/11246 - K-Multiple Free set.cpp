#include <cstdio>

using namespace std;

int main(){
    int T,k,n;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&n,&k);
        
        int ans = 0;
        
        for(long long powK = 1;powK <= n;powK *= k * k){
            int M = n / powK;
            
            ans += M - M / k;
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
