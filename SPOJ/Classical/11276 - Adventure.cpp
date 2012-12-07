#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 50000
#define MOD 1000000007

int mu[MAXN + 1],factor[MAXN + 1];

unsigned int visible(int X, int Y){
    unsigned int ret = 0;
    
    for(int s = 1,e;s <= X && s <= Y;s = e + 1){
        int kx = X / s,ky = Y / s;
        e = min(X / kx,Y / ky);
        ret += (unsigned int)(mu[e] - mu[s - 1]) * kx * ky;
    }
    
    return ret;
}

long long visible(int X, int Y, int Z){
    long long ret = 0;
    
    for(int s = 1,e;s <= X && s <= Y && s <= Z;s = e + 1){
        int kx = X / s,ky = Y / s,kz = Z / s;
        e = min(X / kx,min(Y / ky,Z / kz));
        ret += (long long)(mu[e] - mu[s - 1]) * kx * ky * kz;
    }
    
    return ret;
}

long long solve(int X, int Y, int Z){
    long long ret = visible(X,Y,Z) + visible(X,Y) + visible(Y,Z) + visible(Z,X);
    
    if(X >= 1) ++ret;
    if(Y >= 1) ++ret;
    if(Z >= 1) ++ret;
    
    return ret;
}

long long powsum[11][MAXN + 1];

int main(){
    mu[1] = 1;
    
    for(int i = 2;i <= MAXN;++i){
        if(!factor[i]){
            mu[i] = -1;
            
            if(i <= MAXN / i)
                for(int j = i*i;j <= MAXN;j += i)
                    factor[j] = i;
        }else{
            int aux = i,cont = 0,p = factor[i];
            
            while(aux % p == 0 && cont < 2){
                aux /= p;
                ++cont;
            }
            
            if(cont == 2) mu[i] = 0;
            else mu[i] = -mu[i / p];
        }
    }
    
    for(int i = 1;i <= MAXN;++i) mu[i] += mu[i - 1];
    
    for(int i = 1;i <= 10;++i){
        long long p = 1;
        
        for(int j = 1;j <= MAXN;++j){
            p = p * i % MOD;
            powsum[i][j] = p + powsum[i][j - 1];
            if(powsum[i][j] >= MOD) powsum[i][j] -= MOD;
        }
    }
    
    int T,A,B,C,K;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d %d %d",&A,&B,&C,&K);
        
        long long ans = 0;
        
        for(int s = 1,e;s <= A || s <= B || s <= C;s = e + 1){
            int ka = A / s,kb = B / s,kc = C / s;
            e = min((s > A? MAXN : A / ka),min((s > B? MAXN : B / kb),(s > C? MAXN : C / kc)));
            ans = (ans + solve(ka,kb,kc) % MOD * (powsum[K][e] - powsum[K][s - 1])) % MOD;
        }
        
        if(ans < 0) ans += MOD;
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
