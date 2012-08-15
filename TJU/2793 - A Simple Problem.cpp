#include <cstdio>

using namespace std;

int main(){
    int T,N;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        int ans = N;
        
        for(int i = 2;i <= N / i;++i){
            if(N % i == 0){
                ans /= i;
                
                while(N % i == 0)
                    N /= i;
            }
        }
        
        if(N > 1) ans /= N;
        ++ans;
        
        printf("%d\n",ans);
    }
    
    return 0;
}
