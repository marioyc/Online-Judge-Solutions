#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

long long f(int n){
    if(n==0) return 0;
    long long ans = 0;
    int i,r = (int)floor(sqrt(n));
    
    if(r*r==n){
        ans += n/r;
        --r;
    }
    
    for(i = 1;i<=r;++i){
        ans += n/i;
        ans += max(0,n/i-r);
    }
    
    return ans;
}

int main(){
    int T,n;
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&n);
        printf("%lld\n",f(n));
    }
    
    return 0;
}
