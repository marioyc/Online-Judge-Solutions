#include <cstdio>

using namespace std;

int main(){
    int T,N;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        if(N & 1) printf("0\n");
        else{
            int ans = 0;
            N >>= 1;
            
            for(int i = 1;i <= N / i;++i){
                if(N % i == 0){
                    if(i != N / i) ans += 2;
                    else ++ans;
                }
            }
            
            printf("%d\n",ans);
        }
    }
    
    return 0;
}
