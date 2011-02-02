#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_SIZE 10
#define MOD 1000000000
int size;

struct Matrix{
    long long X[MAX_SIZE][MAX_SIZE];
    
    Matrix(){}
    
    void init(){
        memset(X,0,sizeof(X));
        for(int i = 0;i<size;++i) X[i][i] = 1;
    }
}aux;

void mult(Matrix &m, Matrix &m1, Matrix &m2){
    memset(m.X,0,sizeof(m.X));

    for(int i = 0;i<size;++i)
        for(int j = 0;j<size;++j)
            for(int k = 0;k<size;++k)
                m.X[i][k] = (m.X[i][k]+m1.X[i][j]*m2.X[j][k])%MOD;
}

Matrix pow(Matrix &M0, int n){
	Matrix ret;
	ret.init();
	
	if(n==0) return ret;
	if(n==1) return M0;
	
	Matrix P = M0;
	
	while(n!=0){
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
    int T,b[10],c[10],n;
    Matrix M0,ret;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&size);
        
        for(int i = 0;i<size;++i) scanf("%d",&b[i]);
        for(int i = 0;i<size;++i) b[i] %= MOD;
        for(int i = 0;i<size;++i) scanf("%d",&c[i]);
        
        scanf("%d",&n);
        --n;
        
        if(n<size) printf("%d\n",b[n]);
        else{
            memset(M0.X,0,sizeof(M0.X));
            
            for(int i = 0;i<size;++i) M0.X[0][i] = c[i];
            for(int i = 1;i<size;++i) M0.X[i][i-1] = 1;
            
            ret = pow(M0,n-size+1);
            
            long long ans = 0;
            
            for(int i = 0;i<size;++i)
                ans = (ans+ret.X[0][i]*b[size-1-i])%MOD;
            
            printf("%lld\n",ans);
        }
    }
    
    return 0;
}
