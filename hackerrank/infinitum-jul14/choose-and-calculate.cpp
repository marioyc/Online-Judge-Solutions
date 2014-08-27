#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 100005
#define MOD 1000000007

int N,K,a[MAXN];
long long fact[MAXN],inv_fact[MAXN];

int mod_pow(long long a, int b){
    long long ret = 1;
    
    while(b){
        if(b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    
    return ret;
}

long long comb(int n, int m){
    return fact[n] * inv_fact[m] % MOD * inv_fact[n - m] % MOD;
}

int main(){
    scanf("%d %d",&N,&K);
    
    if(K == 1){
        printf("0\n");
        return 0;
    }
    
    for(int i = 0;i < N;++i)
        scanf("%d",&a[i]);
    sort(a,a + N);
    
    fact[0] = inv_fact[0] = 1;
    
    for(int i = 1;i <= N;++i){
        fact[i] = fact[i - 1] * i % MOD;
        inv_fact[i] = mod_pow(fact[i],MOD - 2);
    }
    
    int ans = 0;
    
    for(int i = 0;i < N;){
        int e = i;
        
        while(e < N && a[e] == a[i]) ++e;
        
        if(e >= K)
            ans = (ans + (comb(e,K) - comb(i,K)) * a[i]) % MOD;
        
        i = e;
    }
    
    for(int i = N - 1;i >= 0;){
        int e = i;
        
        while(e >= 0 && a[e] == a[i]) --e;
        
        if(N - 1 - e >= K)
            ans = (ans - (comb(N - 1 - e,K) - comb(N - 1 - i,K)) * a[i]) % MOD;
        
        i = e;
    }
    
    if(ans < 0) ans += MOD;
    printf("%d\n",ans);
    
    return 0;
}
