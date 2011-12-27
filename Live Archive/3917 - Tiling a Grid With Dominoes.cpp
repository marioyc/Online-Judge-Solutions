#include <cstdio>

using namespace std;

int main(){
    int T,N;
    long long f[1001],g[1001],h[1001];
    
    f[1] = 1; f[2] = 5;
    g[1] = 1; g[2] = 2;
    h[1] = 1; h[2] = 1;
    
    for(int i = 3;i <= 1000;++i){
        f[i] = f[i - 1] + f[i - 2] + 2 * g[i - 1] + h [i - 1];
        g[i] = f[i - 1] + g[i - 1];
        h[i] = f[i - 1] + h[i - 2];
    }
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d",&N);
        printf("%d %lld\n",tc,f[N]);
    }
    
    return 0;
}
