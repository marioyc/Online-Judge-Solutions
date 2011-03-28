#include <cstdio>

using namespace std;

int main(){
    int T,N;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        int ans = 1;
        
        for(int i = 2;i <= N/i;++i){
            if(N % i == 0){
                int exp = 0;
                
                while(N % i == 0){
                    N /= i;
                    ++exp;
                }
                
                ans *= exp+1;
            }
        }
        
        if(N != 1) ans *= 2;
        
        printf("%d\n",ans);
    }
    
    return 0;
}
