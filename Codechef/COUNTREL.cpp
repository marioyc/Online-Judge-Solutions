#include <cstdio>

using namespace std;

const int MOD = 100000007;

long long pow(int a, long long b){
    if(b==0) return 1;
    
    long long ret = pow(a,b/2);
    ret = (ret*ret)%MOD;
    
    if(b & 1) ret = (ret*a)%MOD;
    
    return ret;
}

long long R1(long long N){
    long long ret = ((pow(3,N)-pow(2,N+1)+1)%MOD+MOD)%MOD;
    return (ret*50000004)%MOD;
}

long long R2(long long N){
    long long ret = ((pow(4,N)-pow(3,N+1)+3*pow(2,N)-1)%MOD+MOD)%MOD;
    return (ret*50000004)%MOD;
}

int main(){
    int T;
    scanf("%d",&T);
    
    long long N;
    
    while(T--){
        scanf("%lld",&N);
        printf("%lld %lld\n",R1(N),R2(N));
    }
    
    return 0;
}
