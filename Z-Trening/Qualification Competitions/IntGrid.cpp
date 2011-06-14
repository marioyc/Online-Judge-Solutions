#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    
    long long ans = ((long long)(n+1) * (m+1) + __gcd(n,m) + 1) / 2;
    printf("%lld\n",ans);
    
    return 0;
}
