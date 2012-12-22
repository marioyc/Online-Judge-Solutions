#include <cstdio>

#define MOD 1000000007

long long mod_pow(long long a, int b){
    long long ret = 1;
    
    while(b){
        if(b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    
    return ret;
}

int main(){
    int T,N;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d",&N);
        
        printf("Case #%d: %lld\n",tc,N * mod_pow(2,N - 1) % MOD);
    }
    
    return 0;
}
