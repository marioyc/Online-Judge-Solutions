#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T,N;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        if(N % 2 == 1) printf("1\n");
        else{
            int k = 0;
            
            while((1 << k) <= N) ++k;
            int ans = N - 1;
            
            for(int i = 2;i <= k;++i){
                int x = (i == k? 1 : (k ^ 1 ^ i));
                
                if(x < i){
                    if((1 << (i - 2)) <= (1 << x) - 1)
                        ans = min(ans,(1 << (i - 2)));
                    else
                        ans = min(ans,(1 << (i - 1)) - (1 << x) + 1);
                }
            }
            
            printf("%d\n",ans);
        }
    }
    
    return 0;
}
