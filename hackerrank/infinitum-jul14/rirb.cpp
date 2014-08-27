#include <cstdio>

using namespace std;

long long total_bits(long long n){
    if(n == 0) return 0;
    
    long long ret = 0;
    
    for(int i = 63 - __builtin_clzll(n);i >= 0;--i){
        if(n >> i & 1){
            ret += i * (1LL << (i - 1));
            ret += (n - (n ^ (1LL << i) | ((1LL << i) - 1)));
        }
    }
    
    return ret;
}

double sum_prob(long long n){
    if(n == 0) return 0;
    
    double ret = 0;
    int b = 63 - __builtin_clzll(n);
    
    ret += (double)(total_bits(n) - total_bits((1LL << b) - 1)) / (b + 1);
    
    for(int i = b - 1;i >= 0;--i){
        long long a = (1LL << i),b = (1LL << (i + 1)) - 1;
        ret += (double)(total_bits(b) - total_bits(a - 1)) / (i + 1);
    }
    
    return ret;
}

int main(){
    int T;
    long long A,B;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%lld %lld",&A,&B);
        printf("%.5f %.5f\n",(sum_prob(B) - sum_prob(A - 1)) / (B - A + 1),(double)(total_bits(B) - total_bits(A - 1)) / (B - A + 1));
    }
    
    return 0;
}
