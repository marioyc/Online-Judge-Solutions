#include <cstdio>
#include <algorithm>

using namespace std;

long long solve(long long x, int m){
    long long ret = 0;
    
    while(x <= m){
        ret += m - x;
        x <<= 1;
    }
    
    return ret;
}

int main(){
    int n,m;
    
    scanf("%d %d",&n,&m);
    
    int g = 0;
    
    for(int i = 0,a;i < n;++i){
        scanf("%d",&a);
        g = __gcd(g,a - 1);
    }
    
    while((g & 1) == 0) g >>= 1;
    
    long long ans = 0;
    
    for(int i = 1;i <= g / i;i += 2){
        if(g % i == 0){
            ans += solve(i,m);
            if(g / i != i) ans += solve(g / i,m);
        }
    }
    
    printf("%I64d\n",ans);
    
    return 0;
}
