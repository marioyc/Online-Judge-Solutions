#include <cstdio>
#include <cassert>

using namespace std;

long long extGcd(long long  a, long long b, long long &x, long long &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    
    long long g = extGcd(b,a % b,y,x);
    y -= a / b * x;
    return g;
}

long long modInv(long long a, long long m){
    long long x,y;
    extGcd(a, m, x, y);
    return (x % m + m) % m;
}

long long pow(long long a, int b, int c){
    long long ret = 1;
    
    while(b){
        if(b & 1) ret = ret * a % c;
        a = a * a % c;
        b >>= 1;
    }
    
    return ret;
}

int mod[] = {2,41 * 41,148721};
int rem[3];

long long chinese_remainder(){
    long long ans = rem[0],m = mod[0];
  
    for(int i = 1;i < 3;++i){
        int a = modInv(m,mod[i]);
        int b = modInv(mod[i],m);
        
        ans = (ans * b * mod[i] + (long long)rem[i] * a * m) % (m * mod[i]);
        m *= mod[i];
    }
    
    
    return ans;
}

long long fact1[200001],fact2[148721];

// comb(2n,n)
int comb(int n){
    rem[0] = 0;
    
    int e1 = 0;
    int aux = 2 * n;
    
    while(aux){
        e1 += aux / 41;
        aux /= 41;
    }
    
    int e2 = 0;
    aux = n;
    
    while(aux){
        e2 += aux / 41;
        aux /= 41;
    }
    
    e1 -= 2 * e2;
    
    if(e1 >= 2) rem[1] = 0;
    else{
        rem[1] = fact1[2 * n] * modInv(fact1[n] * fact1[n] % mod[1],mod[1]) % mod[1];
        if(e1 == 1) rem[1] = rem[1] * 41 % mod[1];
    }
    
    if(2 * n >= mod[2]) rem[2] = 0;
    else rem[2] = fact2[2 * n] * pow(fact2[n] * fact2[n] % mod[2],mod[2] - 2,mod[2]) % mod[2];
    
    return chinese_remainder();
}

#define MOD 1000000007
#define MOD2 1000000006

int main(){
    fact1[0] = 1;
    
    for(int i = 1;i <= 200000;++i){
        int aux = i;
        
        while(aux % 41 == 0) aux /= 41;
        
        fact1[i] = fact1[i - 1] * aux % 1681;
    }
    
    fact2[0] = 1;
    
    for(int i = 1;i < 148721;++i)
        fact2[i] = fact2[i - 1] * i % 148721;
    
    int p = 2,q = 500000003;
    int invq = 1,invp = 250000002;
    
    int T,a,b,n;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d %d",&a,&b,&n);
        
        long long x = 0;
        
        if(b != 0){
            int remp = (b % 2 == 0? 0 : 1);
            long long remq = pow(b,comb(n),q);
            x = (remp * q * invq + remq * p * invp) % MOD2;
        }
        
        x = pow(a,x,MOD);
        
        printf("%lld\n",x);
    }
    
    return 0;
}
