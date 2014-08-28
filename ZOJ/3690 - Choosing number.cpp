#include <cstdio>

using namespace std;

#define MOD 1000000007

struct Matrix{
    long long a,b,c,d;
    
    Matrix(){
        a = d = 1;
        b = c = 0;
    }
    
    Matrix(long long _a, long long _b, long long _c, long long _d):
        a(_a),b(_b),c(_c),d(_d){}
    
    Matrix operator * (Matrix X){
        return Matrix(
            (a * X.a + b * X.c) % MOD,
            (a * X.b + b * X.d) % MOD,
            (c * X.a + d * X.c) % MOD,
            (c * X.b + d * X.d) % MOD);
    }
    
    Matrix pow(int n){
        Matrix ret,a = *this;
        
        while(n){
            if(n & 1) ret = ret * a;
            a = a * a;
            n >>= 1;
        }
        
        return ret;
    }
};

int main(){
    int N,M,K;
    Matrix M0;
    
    while(scanf("%d %d %d",&N,&M,&K) == 3){
        M0.a = M - K; M0.b = M - K;
        M0.c = K; M0.d = K - 1;
        
        M0 = M0.pow(N - 1);
        
        printf("%lld\n",((M0.a + M0.c) * (M - K) + (M0.b + M0.d) * K) % MOD);
    }
    
    return 0;
}
