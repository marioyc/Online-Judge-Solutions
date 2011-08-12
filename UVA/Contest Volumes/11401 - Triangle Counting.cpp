#include <cstdio>

using namespace std;

long long sum1(long long n){
    return n * (n + 1) / 2;
}

long long sum2(long long n){
    return n * (n + 1) / 2 * (2*n + 1) / 3;
}

int main(){
    long long n,m,ans;
    
    while(true){
        scanf("%lld",&n);
        if(n < 3) break;
        
        m = (n+1) / 2;
        
        ans = -3 * (sum2(m - 1) - sum2(1)) + (2*n + 3) * (sum1(m - 1) - sum1(1)) - 2*n * (m - 2);
        ans += (sum2(n - 2) - sum2(m - 1)) - (2*n - 1) * (sum1(n - 2) - sum1(m - 1)) + (n*n - n) * (n - 1 - m);
        
        ans /= 2;
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
