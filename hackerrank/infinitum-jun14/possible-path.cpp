#include <cstdio>
#include <algorithm>

using namespace std;

bool solve(long long a, long long b, long long x, long long y){
    if(a == 0 && b == 0)
        return x == 0 && y == 0;
    
    if(x == 0 && y == 0)
        return a == 0 && b == 0;
    
    a = abs(a); b = abs(b); x = abs(x); y = abs(y);
    
    return __gcd(a,b) == __gcd(x,y);
}

int main(){
    int T;
    long long a,b,x,y;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%lld %lld %lld %lld",&a,&b,&x,&y);
        if(solve(a,b,x,y)) printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}
