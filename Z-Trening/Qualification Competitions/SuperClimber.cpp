#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_SIZE 51
const int MOD = 321555123;
int size;

struct Matrix{
    long long X[MAX_SIZE][MAX_SIZE];
    
    Matrix(){}
    
    void init(){
        memset(X,0,sizeof(X));
        for(int i = 0;i < size;++i) X[i][i] = 1;
    } 
}aux;

void mult(Matrix &m, Matrix &m1, Matrix &m2){
    memset(m.X,0,sizeof(m.X));

    for(int i = 0;i<size;++i)
        for(int j = 0;j<size;++j)
            for(int k = 0;k<size;++k)
                m.X[i][k] = (m.X[i][k] + m1.X[i][j]*m2.X[j][k]) % MOD;
}

Matrix pow(Matrix &M0, long long n){
	Matrix ret;
	ret.init();
	
	if(n==0) return ret;
	if(n==1) return M0;
	
	Matrix P = M0;
	
	while(n != 0){
	    if(n & 1){
	        aux = ret;
	        mult(ret,aux,P);
	    }
	    
	    n >>= 1;
	    
	    aux = P;
	    mult(P,aux,aux);
	}
	
    return ret;
}

int main(){
    long long N;
    int K;
    
    scanf("%lld %d",&N,&K);
    size = 2*K + 1;
    
    Matrix M0;
    memset(M0.X,0,sizeof(M0.X));
    
    for(int i = 0;i <= 2 * K;++i){
        if(i > 0) M0.X[i][i-1] = 1;
        M0.X[i][i] = 1;
        if(i+1 <= 2*K) M0.X[i][i+1] = 1;
    }
    
    Matrix ret = pow(M0,N);
    int ans = 0;
    
    for(int i = 0;i <= 2*K;++i){
        ans += ret.X[i][K];
        if(ans >= MOD) ans -= MOD;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
