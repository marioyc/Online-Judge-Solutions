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

long long inv(int x){
    return mod_pow(x,MOD - 2);
}

int main(){
    int N;
    
    scanf("%d",&N);
    
    long long ans = 1;
    
    for(int i = 0;i < N;++i)
        ans = ans * (2 * N - i) % MOD * inv(1 + i) % MOD;
    
    ans = ans * inv(1 + N) % MOD;
    
    printf("%d\n",(int)ans);
    
    return 0;    
}
