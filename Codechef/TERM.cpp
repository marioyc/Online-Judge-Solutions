#include <cstdio>

using namespace std;

const int MOD = 1000003;

// a^b mod c
int pow(int a, int b, int c){
    int ret = 1;
    
    while(b){
        if(b & 1) ret = (long long)ret*a%c;
        a = (long long)a*a%c;
        b >>= 1;
    }
    
    return ret;
}

int main(){
    int T,P,n,ways[100],sum[100],inv[100];
    long long N,K;
    
    for(int i = 1;i<100;++i)
        inv[i] = pow(i,MOD-2,MOD);
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%lld %lld %d",&N,&K,&P);
        
        if(P==1){
            puts("0");
            continue;
        }
        
        ways[0] = sum[0] = 1;
        K %= MOD;
        
        for(int i = 1;i<P;++i){
            ways[i] = ways[i-1]*(i+K-1)*inv[i] % MOD;
            sum[i] = sum[i-1]+ways[i];
            if(sum[i]>=MOD) sum[i] -= MOD;
        }
        
        long long ans = 1;
        int d = 0, pow_sum = 1;
        
        while(N>0){
            n = N%P;
            ans = (ans*ways[n]+(n>0? (long long)sum[n-1]*pow_sum % MOD : 0))%MOD;
            pow_sum = (long long)pow_sum*sum[P-1] % MOD;
            N /= P; ++d;
        }
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
