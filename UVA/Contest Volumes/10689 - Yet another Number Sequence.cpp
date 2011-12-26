#include <cstdio>
#include <cstring>

using namespace std;

struct Matrix{
    int A[2][2];
    
    Matrix(){}
    
    Matrix operator * (Matrix B){
        Matrix C;
        
        memset(C.A,0,sizeof C.A);
        
        for(int i = 0;i < 2;++i){
            for(int j = 0;j < 2;++j){
                for(int k = 0;k < 2;++k)
                    C.A[i][j] += A[i][k] * B.A[k][j];
                
                C.A[i][j] %= 10000;
            }
        }
        
        return C;
    }
    
    Matrix pow(int n){
        Matrix ret,aux = *this;
        
        ret.A[0][0] = 1; ret.A[0][1] = 0;
        ret.A[1][0] = 0; ret.A[1][1] = 1;
        
        while(n){
            if(n & 1) ret = ret * aux;
            aux = aux * aux;
            n >>= 1;
        }
        
        return ret;
    }
};

int main(){
    Matrix M,P;
    
    M.A[0][0] = 1; M.A[0][1] = 1;
    M.A[1][0] = 1; M.A[1][1] = 0;
    
    int T,a,b,n,m;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d %d %d",&a,&b,&n,&m);
        
        int ans = a;
        
        if(n > 0){
            P = M.pow(n - 1);
            ans = P.A[0][0] * b + P.A[0][1] * a;
        }
        
        if(m == 1) ans %= 10;
        if(m == 2) ans %= 100;
        if(m == 3) ans %= 1000;
        if(m == 4) ans %= 10000;
        
        printf("%d\n",ans);
    }
    
    return 0;
}
