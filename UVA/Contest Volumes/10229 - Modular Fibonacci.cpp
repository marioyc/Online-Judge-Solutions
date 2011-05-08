#include <cstdio>
#include <cstring>

using namespace std;

int MOD;

struct Matrix{
    long long X[2][2];
    
    Matrix(){}
    
    void init(){
        memset(X,0,sizeof(X));
        for(int i = 0;i < 2;++i) X[i][i] = 1;
    }
}aux;

void mult(Matrix &m, Matrix &m1, Matrix &m2){
    memset(m.X,0,sizeof(m.X));

    for(int i = 0;i < 2;++i)
        for(int j = 0;j < 2;++j)
            for(int k = 0;k < 2;++k)
                m.X[i][k] = (m.X[i][k] + m1.X[i][j] * m2.X[j][k]) % MOD;
}

Matrix pow(Matrix &M0, int n){
	Matrix ret;
	ret.init();
	
	if(n == 0) return ret;
	if(n == 1) return M0;
	
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
    Matrix M0;
    M0.X[0][0] = M0.X[0][1] = M0.X[1][0] = 1;
    M0.X[1][1] = 0;
    
    int n,m;
    
    while(scanf("%d %d",&n,&m) == 2){
        MOD = (1 << m);
        printf("%lld\n",pow(M0,n).X[0][1]);
    }
    
    return 0;
}
