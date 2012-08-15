#include <cstdio>

using namespace std;

#define MOD 1000000007
#define MOD2 1000000006

int pow(long long a, int b, int c){
    long long ret = 1;
    
    while(b){
        if(b & 1) ret = ret * a % c;
        a = a * a % c;
        b >>= 1;
    }
    
    return ret;
}

long long fact[200001];

int main(){
    int p = 2,q = 500000003;
    int invp = 250000002;
    
    fact[0] = 1;
    
    for(int i = 1;i <= 200000;++i)
        fact[i] = fact[i - 1] * i % q;
    
    int T,a,b,n;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d %d",&a,&b,&n);
        
        long long remq = fact[2 * n] * pow(fact[n] * fact[n] % q,q - 2,q) % q;
        long long x = remq * p * invp % MOD2;
        x = pow(x,b,MOD2);
        x = pow(a,x,MOD);
        
        printf("%lld\n",x);
    }
    
    return 0;
}
