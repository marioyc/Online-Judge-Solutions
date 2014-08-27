#include <cstdio>

using namespace std;

int main(){
    int T;
    long long p,L;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%lld %lld",&p,&L);
        
        long long a = (L / p) / p,b = (L / p) % p,c = L % p;
        long long ans = 0;
        
        if(a > 0)
            ans += a * p;
        
        long long aux = 0;
        
        while(a){
            aux += a;
            a /= p;
        }
        
        aux %= p;
        
        if(aux > 0)
            aux = p - aux;
        
        if(aux < b) ans += p;
        else if(aux == b) ans += c + 1;
        
        printf("%lld\n",ans - 1);
    }
    
    return 0;
}
