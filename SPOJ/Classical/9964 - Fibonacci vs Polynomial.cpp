#include <cstdio>
#include <cstring>

using namespace std;

#define MOD 1111111111
int sz;

long long memo[101][101];

long long comb(int n, int m){
    if(m == 0 || m == n) return 1;
    
    long long &ret = memo[n][m];
    
    if(ret == -1){
        ret = comb(n - 1,m) + comb(n - 1,m - 1);
        if(ret >= MOD) ret -= MOD;
    }
    
    return ret;
}

struct Matrix{
    long long M[103][103];
    
    void init(){
        memset(M,0,sizeof M);
        
        for(int i = 0;i < sz;++i)
            M[i][i] = 1;
    }
    
    Matrix operator * (Matrix &X){
        Matrix ret;
        
        for(int i = 0;i < sz;++i){
            for(int j = 0;j < sz;++j){
                long long aux = 0;
                
                for(int k = 0;k < sz;++k){
                    aux += M[i][k] * X.M[k][j];
                    if(aux >= MOD) aux %= MOD;
                }
                
                ret.M[i][j] = aux;
            }
        }
        
        return ret;
    }
    
    Matrix pow(int b){
        Matrix ret,a = *this;
        ret.init();
        
        while(b){
            if(b & 1) ret = ret * a;
            a = a * a;
            b >>= 1;
        }
        
        return ret;
    }
};

int main(){
    int n,d;
    
    scanf("%d %d",&n,&d);
    
    if(n <= 1) puts("1");
    else{
        Matrix M0;
        sz = d + 3;
        
        memset(M0.M,0,sizeof M0.M);
        
        M0.M[0][0] = M0.M[0][1] = M0.M[1][0] = 1;
        
        for(int i = 0;i <= d;++i)
            scanf("%lld",&M0.M[0][sz - 1 - i]);
        
        memset(memo,-1,sizeof memo);
        
        for(int i = 0;i <= d;++i)
            for(int j = d - i;j >= 0;--j)
                M0.M[i + 2][i + 2 + d - i - j] = comb(d - i,j);
        
        long long ans = 0,pow2 = 1;
        
        M0 = M0.pow(n - 1);
        
        for(int i = sz - 1;i >= 2;--i){
            ans = ans + M0.M[0][i] * pow2;
            if(ans >= MOD) ans %= MOD;
            
            pow2 *= 2;
            if(pow2 >= MOD) pow2 -= MOD;
        }
        
        ans = (ans + M0.M[0][0] + M0.M[0][1]) % MOD;
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
