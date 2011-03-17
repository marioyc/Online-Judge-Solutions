#include <cstdio>
#include <cstring>

using namespace std;

int MOD;
int size = 24;

struct Matrix{
    long long X[24][24];
    
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
    char A,B;
    int L;
    
    scanf("%c %c",&A,&B);
    scanf("%d %d",&L,&MOD);
    
    int adj[][3] = {
        {1,3,4},
        {0,2,5},
        {1,3,6},
        {0,2,7},
        {0,5,7},
        {1,4,6},
        {2,5,7},
        {3,4,6},
    };
    
    Matrix M0;
    memset(M0.X,0,sizeof(M0.X));
    
    int u,v,w;
    
    for(int i = 0;i<8;++i){
        for(int ki = 0;ki<3;++ki){
            u = 3*i+ki;
            
            for(int j = 0;j<3;++j){
                if(j==ki) continue;
                v = adj[i][j];
                
                for(int kj = 0;kj<3;++kj){
                    if(adj[v][kj]==i){
                        w = 3*v+kj;
                        M0.X[u][w] = 1;
                    }
                }
            }
        }
    }
    
    Matrix ret = pow(M0,L-1);
    
    int ans = 0;
    
    u = A-'A';
    v = B-'A';
    
    for(int i = 0;i<24;++i){
        int a = i/3,b = i%3;
        
        if(adj[a][b]==u){
            for(int j = 0;j<3;++j){
                ans += ret.X[i][3*v+j];
                if(ans>=MOD) ans -= MOD;
            }
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}
