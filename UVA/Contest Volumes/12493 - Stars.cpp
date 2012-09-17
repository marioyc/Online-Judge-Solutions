#include <cstdio>

using namespace std;

int main(){
    int N;
    
    while(scanf("%d",&N) == 1){
        int ans = 1;
        
        for(int i = 2;i <= N / i;++i){
            if(N % i == 0){
                int aux = 1;
                
                while(N % i == 0){
                    N /= i;
                    aux *= i;
                }
                
                ans *= aux - aux / i;
            }
        }
        
        if(N > 1) ans *= N - 1;
        
        printf("%d\n",(ans + 1) / 2);
    }
    
    return 0;
}
