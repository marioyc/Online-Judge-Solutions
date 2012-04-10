#include <cstdio>

using namespace std;

int main(){
    long long N;
    
    while(scanf("%lld",&N) == 1)
        printf("%lld\n",(N + 1) * N * (N + 1) / 2 - N * (N + 1) * (2*N + 1) / 6);
    
    return 0;
}
