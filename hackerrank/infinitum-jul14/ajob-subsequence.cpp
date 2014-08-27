#include <cstdio>

using namespace std;

#define MAXP 100000

int p;
long long fact[MAXP];

long long get_exp(long long n){
    long long ret = 0;
    
    while(n){
        n /= p;
        ret += n;
    }
    
    return ret;
}

int calc(long long n){
    if(n == 0) return 1;
    
    int ret = calc(n / p) * fact[n % p] % p;
    
    if((n / p) & 1)
        ret = p - ret;
    
    return ret;
}

long long mod_pow(long long a, int b){
    long long ret = 1;
    
    while(b){
        if(b & 1) ret = ret * a % p;
        a = a * a % p;
        b >>= 1;
    }
    
    return ret;
}

long long comb(long long n, long long m){
    if(get_exp(n) > get_exp(m) + get_exp(n - m))
        return 0;
    
    return calc(n) * mod_pow((long long)calc(m) * calc(n - m) % p,p - 2) % p;
}

int main(){
    int T;
    
    scanf("%d",&T);
    
    long long N,K;
    
    while(T--){
        scanf("%lld %lld %d",&N,&K,&p);
        
        fact[0] = 1;
        
        for(int i = 1;i < MAXP;++i){
            int aux = i;
            
            while(aux % p == 0)
                aux /= p;
            
            fact[i] = fact[i - 1] * aux % p;
        }
        
        printf("%lld\n",comb(N + 1,K + 1));
    }
    
    return 0;
}
