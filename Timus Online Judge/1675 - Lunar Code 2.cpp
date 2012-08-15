#include <cstdio>

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

long long comb(int n, int m){
    if(m > n - m) m = n - m;
    
    long long num = 1,den = 1;
    
    for(int i = 0;i < m;++i){
        num = num * (n - i) % MOD;
        den = den * (1 + i) % MOD;
    }
    
    return num * mod_pow(den,MOD - 2) % MOD;
}

int main(){
    int M,N,K,L;
    
    scanf("%d %d %d %d",&M,&N,&K,&L);
    
    long long ans = comb(M,K) * comb(N,L) % MOD;
    
    M -= K;
    N -= L;
    
    long long aux = 0;
    
    if(N == 0 && M == 0) aux = 1;
    else if(N == 0 || M == 0) aux = 0;
    else{
        long long C = M;
        int pow2 = 2;
        
        for(int i = M - 1;i >= 0;--i){
            if(i & 1) aux = (aux - C * mod_pow(pow2 - 1,N)) % MOD;
            else aux = (aux + C * mod_pow(pow2 - 1,N)) % MOD;
            
            pow2 <<= 1;
            if(pow2 >= MOD) pow2 -= MOD;
            
            C = C * i % MOD * mod_pow(M - i + 1,MOD - 2) % MOD;
        }
        
        if(aux < 0) aux += MOD;
    }
    
    ans = ans * aux % MOD;
    
    printf("%lld\n",ans);
    
    return 0;
}
