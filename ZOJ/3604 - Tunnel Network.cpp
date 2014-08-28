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

int main(){
    int T,N,S;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&N,&S);
        
        if(N == S) printf("1\n");
        else printf("%lld\n",S * mod_pow(N,N - S - 1) % MOD);
    }
    
    return 0;
}
