#include <cstdio>
#include <numeric>

using namespace std;

#define MAXN 10001

int phi[MAXN + 1],factor[MAXN + 1];

int main(){
    phi[1] = 1;
    
    for(int i = 2;i <= MAXN;++i){
        if(!factor[i]){
            phi[i] = i - 1;
            
            if(i <= MAXN / i)
                for(int j = i*i;j <= MAXN;j += i)
                    factor[j] = i;
        }else{
            int aux = i,aux2 = 1,p = factor[i];
            
            while(aux % p == 0){
                aux /= p;
                aux2 *= p;
            }
            
            phi[i] = (aux2 - aux2 / p) * phi[aux];
        }
    }
    
    partial_sum(phi,phi + (MAXN + 1),phi);
    
    int T,N;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        printf("%lld\n",(long long)phi[N] * phi[N]);
    }
    
    return 0;
}
