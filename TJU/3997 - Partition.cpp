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
    int T,n,k;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&n,&k);
        
        if(k == n) printf("1\n");
        else if(k > n) printf("0\n");
        else printf("%lld\n",(mod_pow(2,n - k) + (n == k + 1? 0LL : (n - k - 1) * mod_pow(2,n - k - 2))) % MOD);
    }
    
    return 0;
}
