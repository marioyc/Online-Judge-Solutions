#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T,N,num[50];
    int MOD = 1000000007;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        for(int i = 0;i<N;++i) scanf("%d",&num[i]);
        
        sort(num,num+N);
        
        long long ans = 1;
        
        for(int i = 0;i<N;++i){
            if(num[i]<i+1){
                ans = 0;
                break;
            }else ans = (ans*(num[i]-i))%MOD;
        }
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
