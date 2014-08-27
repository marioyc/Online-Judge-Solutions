#include <cstdio>

using namespace std;

int main(){
    int T;
    long long n,m;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%lld %lld",&n,&m);
        
        printf("%lld\n",n / m * (m - 1) * m / 2 + (n % m) * (n % m + 1) / 2);
    }
    
    return 0;
}
