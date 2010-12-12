#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    long long X,Y;
    
    while(scanf("%lld %lld",&X,&Y)==2)
        printf("%lld\n",Y/__gcd(X,Y));
    
    return 0;
}
