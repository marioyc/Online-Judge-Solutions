#include <cstdio>
#include <cstring>

using namespace std;

#define MAX_SIZE 6
#define MOD 10007

const int size = 6;

struct Matrix{
    int X[MAX_SIZE][MAX_SIZE];
    
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

Matrix exp(Matrix &M0, int n){
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
	int n,coef[size] = {56,16,4,1,44,16};
	Matrix M0;
	
	for(int i=0;i<size;++i)
	    for(int j=0;j<size;++j)
	        M0.X[i][j] = 0;
	
	M0.X[0][1] = 4; M0.X[0][2] = 8; M0.X[0][3] = 4; M0.X[0][4] = 2;
	M0.X[1][0] = 1; M0.X[2][1] = 1; M0.X[3][2] = 1;
	M0.X[4][4] = 2; M0.X[4][5] = 2; M0.X[5][4] = 1;
	
	while(true){
		scanf("%d",&n);
		if(n==-1) break;
		else{
			int ans;
			
			if(n==0) ans = 1;
			else if(n==1) ans = 4;
			else if(n==2) ans = 16;
			else if(n==3) ans = 56;
			else{
				Matrix res = exp(M0,n-3);
				ans = 0;
				for(int i=0;i<size;++i)
					ans = (ans+coef[i]*res.X[0][i])%MOD;
			}
			
			printf("%d\n",ans);
		}
	}
	
	return 0;
}
