#include <cstdio>
#include <numeric>

using namespace std;

long long f[1000001];

int main(){
    for(int i = 1;i <= 1000000;++i)
        f[i] = (long long)(i / 2 - 1) * (i / 2) + (long long)(i - 1) * (i - i / 2 - 1) - (long long)(i - 1) * i / 2 + i / 2;
    
    partial_sum(f,f + 1000001,f);
    
    int T,N;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        printf("%lld\n",f[N]);
    }
    
    return 0;
}
