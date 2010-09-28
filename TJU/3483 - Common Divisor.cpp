#include <cstdio>
#include <algorithm>

using namespace std;

long long numDivisors(int n){
    long long ans = 1;
    int aux;
    
    if((n&1)==0){
        aux = 1;
        while((n&1)==0){
            n >>= 1;
            ++aux;
        }
        ans *= aux;
    }
    
    for(int i=3;i*i<=n;i+=2){
        if(n%i==0){
            aux = 1;
            while(n%i==0){
                n /= i;
                ++aux;
            }
            ans *= aux;
        }
    }
    
    if(n!=1) ans *= 2;
    
    return ans;
}

int main(){
    int T,n,m,G;
    
    scanf("%d",&T);
    
    for(int i=0;i<T;++i){
        scanf("%d %d",&n,&m);
        G = __gcd(n,m);
        
        printf("%lld\n",numDivisors(G));
    }
    
    return 0;
}
