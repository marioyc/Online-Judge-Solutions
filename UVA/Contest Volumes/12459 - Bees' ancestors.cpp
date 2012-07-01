#include <cstdio>

using namespace std;

int main(){
    int N;
    long long x[81],y[81];
    
    x[1] = 1; y[1] = 0;
    
    for(int i = 2;i <= 80;++i){
        x[i] = x[i - 1] + y[i - 1];
        y[i] = x[i - 1];
    }
    
    while(true){
        scanf("%d",&N);
        if(N == 0) break;
        
        printf("%lld\n",x[N] + y[N]);
    }
    
    return 0;
}
