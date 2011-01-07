#include <cstdio>

using namespace std;

const int MOD = 10009;

long long mod_pow(int a, int b){
    long long ret = 1,p = a;
    
    while(b!=0){
        if(b & 1) ret = (ret*p)%MOD;
        b >>= 1;
        p = (p*p)%MOD;
    }
    
    return ret;
}

// Modular inverse using Fermat's Little Theorem
long long inv(int n){
    return mod_pow(n,MOD-2);
}

int zeroes(int n){
    int ret = 0;
    
    while(n!=0){
        ret += n/MOD;
        n /= MOD;
    }
    
    return ret;
}

long long fact[MOD];

long long calc(int n){
    if(n==0) return 1;
    
    long long ret = fact[n%MOD];
    if(n/MOD % 2) ret = MOD-ret;
    
    return (ret*calc(n/MOD))%MOD;
}

long long comb(long long n, long long k){
    int z = zeroes(n)-zeroes(k)-zeroes(n-k);
    if(z>0) return 0;
    
    return calc(n)*inv(calc(k)*calc(n-k)%MOD)%MOD;
}

int main(){
    int T;
    long long n,k;
    
    fact[0] = 1;
    for(int i = 1;i<MOD;++i) fact[i] = (fact[i-1]*i)%MOD;
    
    while(scanf("%lld %lld",&n,&k)==2){
        if(n<k*(k+1)/2) printf("0\n");
        else printf("%lld\n",comb(n-k*(k+1)/2+k-1,k-1));
    }
    
    return 0;
}
