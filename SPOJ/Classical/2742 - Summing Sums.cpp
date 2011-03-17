#include <cstdio>

using namespace std;

const int MOD = 98765431;

long long pow(long long a, long long b){
    long long ret = 1;
    
    while(b){
        if(b & 1) ret = ret*a % MOD;
        a = a*a % MOD;
        b >>= 1;
    }
    
    return ret;
}

int main(){
    int N;
    long long T;
    
    scanf("%d %lld",&N,&T);
    
    int S = 0,a[N];
    
    for(int i = 0;i<N;++i){
        scanf("%d",&a[i]);
        a[i] %= MOD;
        S += a[i];
        if(S>MOD) S -= MOD;
    }
    
    long long c = (pow(N-1,T)+((T & 1)? 1 : -1))*pow(N,MOD-2) % MOD * S % MOD,tmp;
    
    for(int i = 0;i<N;++i){
        tmp = c+((T & 1)? -a[i] : a[i]);
        tmp %= MOD;
        if(tmp<0) tmp += MOD;
        
        printf("%lld\n",tmp);
    }
    
    return 0;
}
