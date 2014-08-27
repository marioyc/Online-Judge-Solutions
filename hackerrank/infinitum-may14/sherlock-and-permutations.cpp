#include <cstdio>
#include <cstring>

using namespace std;

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
    long long fact[2000];
    
    fact[0] = 1;
    
    for(int i = 1;i < 2000;++i)
        fact[i] = fact[i - 1] * i % MOD;
    
    int T,N,M;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&N,&M);
        
        printf("%lld\n",fact[N + M - 1] * mod_pow(fact[M - 1] * fact[N] % MOD,MOD - 2) % MOD);
    }
    
    return 0;
}
