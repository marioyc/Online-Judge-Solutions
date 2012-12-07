#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 1000000

int mu[MAXN + 1],factor[MAXN + 1];
int sum_mu[MAXN + 1];

long long visible(int X, int Y){
    long long ret = 0;
    
    for(int s = 1,e;s <= X && s <= Y;s = e + 1){
        int kx = X / s,ky = Y / s;
        e = min(X / kx,Y / ky);
        ret += (long long)(sum_mu[e] - sum_mu[s - 1]) * kx * ky;
    }
    
    return ret;
}

long long visible(int X, int Y, int Z){
    long long ret = 0;
    
    for(int s = 1,e;s <= X && s <= Y && s <= Z;s = e + 1){
        int kx = X / s,ky = Y / s,kz = Z / s;
        e = min(X / kx,min(Y / ky,Z / kz));
        ret += (long long)(sum_mu[e] - sum_mu[s - 1]) * kx * ky * kz;
    }
    
    return ret;
}

int main(){
    memset(factor,-1,sizeof factor);
    mu[1] = 1;
    sum_mu[1] = 1;
    
    for(int i = 2;i <= MAXN;++i){
        if(factor[i] == -1){
            mu[i] = -1;
            
            if(i <= MAXN / i)
                for(int j = i*i;j <= MAXN;j += i)
                    factor[j] = i;
        }else{
            int cont = 0,aux = i,p = factor[i];
            
            while(aux % p == 0 && cont < 2){
                aux /= p;
                ++cont;
            }
            
            if(cont == 2) mu[i] = 0;
            else mu[i] = -mu[i / p];
        }
        
        sum_mu[i] = sum_mu[i - 1] + mu[i];
    }
    
    int X,Y,Z;
    
    while(scanf("%d %d %d",&X,&Y,&Z) == 3){
        --X; --Y; --Z;
        
        long long ans = visible(X,Y,Z) + visible(X,Y) + visible(Y,Z) + visible(Z,X);
        
        if(X >= 1) ++ans;
        if(Y >= 1) ++ans;
        if(Z >= 1) ++ans;
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
