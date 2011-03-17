#include <cstdio>
#include <cstring>

using namespace std;

int MOD;
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

Matrix P[32];

Matrix pow(Matrix &M0, int n){
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

int f(long long n){
    if(n==0) return 0;
    return pow(P[1],n-1).X[0][0];
}

int main(){
    P[1].X[0][0] = P[1].X[0][1] = P[1].X[1][0] = 1;
    P[1].X[1][1] = 0;
    
    int T,M;
    long long N;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%lld %d",&N,&M);
        
        MOD = (1<<M);
        
        for(int i = 2;i<32;++i)
            mult(P[i],P[i-1],P[i-1]);
        
        printf("%d\n",f(N+1));
    }
    
    return 0;
}
