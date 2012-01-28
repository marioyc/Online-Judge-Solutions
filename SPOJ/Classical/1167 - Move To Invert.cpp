#include <cstdio>
#include <algorithm>

using namespace std;

// Para un n dado
// Queremos escoger 0 <= x < n : cantidad de monedas de la base que no se mueven
// que minimize
// f(x) = (x - 1)*x / 2 + a*(a + 1) / 2 + b*(b + 1) / 2
// donde a + x + b = n

long long f(long long x, long long n){
    return (x - 1) * x / 2 + (n - x) * (n - x + 1) / 2 - ((n - x) / 2) * ((n - x + 1) / 2);
}

int main(){
    int T;
    long long N;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%lld",&N);
        
        printf("%lld\n",min(f((N + 2) / 3,N),f((N + 4) / 3,N)));
    }
    
    return 0;
}
