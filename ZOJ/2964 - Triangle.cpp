/*
    Sea k el menor entero positivo tal que a^k = 1(mod z).
    Además k es divisor de phi(z)
    
    Sean los lados : X<Y<Z
    Entonces : X = ak+x, Y = bk+x, Z = ck+x (a<b<c)
    
    De la desigualdad triangular, se debe cumplir :
    
    ak+x<bk+x+ck+x (siempre cumple)
    bk+x<ck+x+ak+x (siempre cumple)
    ck+x<ak+x+bk+x -> (c-a-b)k<x -> x = (c-a-b)k+1
    
    Luego, se quiere minimizar S = X+Y+Z = 2k(2c-a-b)+3
    
    De a<b<c :
    
    - b<c -> b+1<=c
    - a<b -> a+1<=b -> a+2<=c
    
    Entonces : a+b+3<=2c -> 2c-a-b>=3
    
    a = 1, b = 2, c =3, cumple 2c-a-b = 3
    
    Entonces S_min = 6k+3
*/

#include <cstdio>

using namespace std;

int phi(int n){
    if(n==1) return 1;
    int ret = n;
    
    for(int i = 2;i<=n/i;++i){
        if(n%i==0){
            ret -= ret/i;
            while(n%i==0) n /= i;
        }
    }
    
    if(n!=1) ret -= ret/n;
    
    return ret;
}

long long pow(int a, int b, int mod){
    if(b==0) return 1;
    
    long long aux = pow(a,b/2,mod);
    
    aux = (aux*aux)%mod;
    if(b&1) aux = (aux*a)%mod;
    
    return aux;
}

int main(){
    int T,a,z,m,k;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&a,&z);
        
        if(z==1) k = 1;
        else{
            m = phi(z);
            k = -1;
            
            for(int i = 1;i<=m/i;++i){
                if(m%i==0){
                    if(pow(a,i,z)==1){
                        k = i;
                        break;
                    }else if(pow(a,m/i,z)==1) k = m/i;
                }
            }
        }
        
        printf("%lld\n",6LL*k+3);
    }
    
    return 0;
}
