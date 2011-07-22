#include <cstdio>

using namespace std;

int main(){
    long long N;
    
    scanf("%lld",&N);
    
    printf("%lld\n",N * (N+1) / 2  * (N+2));
    
    return 0;
}
