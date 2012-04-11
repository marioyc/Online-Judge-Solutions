#include <cstdio>

using namespace std;

int main(){
    long long d[13],fact[13];
    d[2] = 1; d[3] = 2;
    
    for(int i = 4;i <= 12;++i)
        d[i] = (i - 1) * (d[i - 1] + d[i - 2]);
    
    fact[0] = 1;
    
    for(int i = 1;i <= 12;++i)
        fact[i] = i * fact[i - 1];
    
    int T,n;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&n);
        printf("%lld/%lld\n",d[n],fact[n]);
    }
    
    return 0;
}
