#include <cstdio>
#include <cstring>

using namespace std;

#define sz 10
#define MOD 2007

struct Matrix{
    int M[sz][sz];
};

void mult(Matrix &a, Matrix &b, Matrix &c){
    memset(c.M,0,sizeof c.M);
    
    for(int i = 0;i < sz;++i){
        for(int j = 0;j < sz;++j){
            for(int k = 0;k < sz;++k)
                c.M[i][j] += a.M[i][k] * b.M[k][j];
            c.M[i][j] %= MOD;
        }
    }
}

Matrix pow(Matrix a, int b){
    Matrix ret,aux;
    
    memset(ret.M,0,sizeof ret.M);
    for(int i = 0;i < sz;++i) ret.M[i][i] = 1;
    
    while(b){
        if(b & 1){
            mult(ret,a,aux);
            ret = aux;
        }
        
        mult(a,a,aux);
        a = aux;
        
        b >>= 1;
    }
    
    return ret;
}

int main(){
    int N,K;
    
    scanf("%d %d",&N,&K);
    
    Matrix A;
    memset(A.M,0,sizeof A.M);
    
    for(int i = 0;i < sz;++i){
        if(i > 0) A.M[i][i - 1] = 1;
        A.M[i][i] = i + 1;
    }
    
    printf("%d\n",pow(A,N - 1).M[K - 1][0]);
    
    return 0;
}
