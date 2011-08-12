#include <cstdio>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b){
    a = abs(a); b = abs(b);
    if(a == 0) return b;
    
    while(b % a != 0){
        b %= a;
        swap(a,b);
    }
    
    return a;
}

int main(){
    long long p,q,X1,Y1,X2,Y2,X,Y;
    
    scanf("%lld %lld",&p,&q);
    scanf("%lld %lld",&X1,&Y1);
    scanf("%lld %lld",&X2,&Y2);
    
    X = X2 - X1; Y = Y2 - Y1;
    
    if(X == 0 && Y == 0) puts("YES");
    else if(p == 0 && q == 0) puts("NO");
    else{
        long long N = p*X - q*Y;
        long long g = gcd(2*p*q,gcd(p*p - q*q,p*p + q*q));
        
        if(N % g == 0) puts("YES");
        else puts("NO");
    }
    
    return 0;
}
