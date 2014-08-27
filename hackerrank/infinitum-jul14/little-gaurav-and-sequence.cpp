#include <cstdio>

using namespace std;

int calc1(int n){
    if(n & 1) return 5;
    return 1;
}

int calc2(int n){
    if(n == 0) return 2;
    n %= 5;
    if(n == 1) return 6;
    if(n == 2) return 2;
    if(n == 3) return 8;
    if(n == 4) return 4;
    return 0;
}

int main(){
    int T;
    long long N;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%lld",&N);
        
        int lg = 63 - __builtin_clzll(N);
        
        printf("%d\n",calc1(N) * calc2(lg) % 10);
    }
    
    return 0;
}
