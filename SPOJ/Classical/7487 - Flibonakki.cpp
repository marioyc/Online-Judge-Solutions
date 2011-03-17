#include <cstdio>
#include <cstring>

using namespace std;

const int MOD = 1000000007;
int size = 2;

struct Matrix{
    long long X[2][2];
    
    Matrix(){}
    
    void init(){
        memset(X,0,sizeof(X));
        for(int i = 0;i<size;++i) X[i][i] = 1;
    }
}aux;

void mult(Matrix &m, Matrix &m1, Matrix &m2){
    m.X[0][0] = (m1.X[0][0] * m2.X[0][0] + m1.X[0][1] * m2.X[1][0]) % MOD;
    m.X[0][1] = (m1.X[0][0] * m2.X[0][1] + m1.X[0][1] * m2.X[1][1]) % MOD;
    m.X[1][0] = (m1.X[1][0] * m2.X[0][0] + m1.X[1][1] * m2.X[1][0]) % MOD;
    m.X[1][1] = (m1.X[1][0] * m2.X[0][1] + m1.X[1][1] * m2.X[1][1]) % MOD;
}

Matrix P[54];

Matrix pow(Matrix &M0, long long n){
	Matrix ret;
	ret.init();
	
	int exp = 1;
	
	while(n){
	    if(n & 1){
	        aux = ret;
	        mult(ret,aux,P[exp]);
	    }
	    
	    n >>= 1;
	    ++exp;
	}
	
    return ret;
}

long long f(long long n){
    if(n==0) return 0;
    return pow(P[1],n-1).X[0][0];
}

// G(n) = (3f(4n+2)-f(4n+3)+3f(2)-f(3))/5
// 5^{-1} = 400000003 (mod 10^9+7)

int main(){
    P[1].X[0][0] = P[1].X[0][1] = P[1].X[1][0] = 1;
    P[1].X[1][1] = 0;
    
    for(int i = 2;i<54;++i)
        mult(P[i],P[i-1],P[i-1]);
    
    int T;
    long long n,aux;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%lld",&n);
        
        aux = (3*f(4*n+2)-f(4*n+3)-1)*400000003 % MOD;
        if(aux<0) aux += MOD;
        
        printf("%lld\n",aux);
    }
    
    return 0;
}
