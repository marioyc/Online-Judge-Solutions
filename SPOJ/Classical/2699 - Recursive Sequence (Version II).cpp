#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_SIZE 16
int MOD,size;

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

Matrix pow(Matrix &M0, long long n){
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

int b[15],c[15],sum[15];
Matrix M0,ret;

int getSum(long long n){
    if(n<0) return 0;
    if(n<size-1) return sum[n];
    
    ret = pow(M0,n-size+2);
    
    long long ans = ret.X[0][0]*sum[size-2]%MOD;
    
    for(int i = 1;i<size;++i)
        ans = (ans+ret.X[0][i]*b[size-1-i])%MOD;
    
    return (int)ans;
}

int main(){
    int T;
    long long n,m;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&size);
        
        for(int i = 0;i<size;++i) scanf("%d",&b[i]);
        for(int i = 0;i<size;++i) scanf("%d",&c[i]);
        
        scanf("%lld %lld %d",&m,&n,&MOD);
        --m; --n;
        
        for(int i = 0;i<size;++i) b[i] %= MOD;
        
        sum[0] = b[0];
        
        for(int i = 1;i<size;++i){
            sum[i] = sum[i-1]+b[i];
            if(sum[i]>=MOD) sum[i] -= MOD;
        }
        
        ++size;
        
        memset(M0.X,0,sizeof(M0.X));
        
        M0.X[0][0] = 1;
        for(int i = 1;i<size;++i) M0.X[0][i] = M0.X[1][i] = c[i-1];
        for(int i = 2;i<size;++i) M0.X[i][i-1] = 1;
        
        int ans = getSum(n)-getSum(m-1);
        if(ans<0) ans += MOD;
        
        printf("%d\n",ans);
    }
    
    return 0;
}
