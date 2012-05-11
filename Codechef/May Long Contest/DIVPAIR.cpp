#include <cstdio>

using namespace std;

long long f(long long x, int M){
    return x * (x / M + 1) - M * (x / M) * (x / M + 1) / 2;
}

int main(){
    int T,N,M;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&N,&M);
        
        if(M - 1 > 2*N - 1) puts("0");
        else{
            int x = 2 * N / M * M - 1;
            
            long long ans = f(x,M);
            
            if(x > N) ans -= 2 * f(x - N,M);
            
            if(M & 1) ans -= N / M;
            else ans -= 2 * N / M;
            
            printf("%lld\n",ans >> 1);
        }
    }
    
    return 0;
}
