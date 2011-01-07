#include <cstdio>

using namespace std;

int main(){
    long long derr[13];
    derr[0] = 1; derr[1] = 0;
    
    for(int i = 2;i<=12;++i) derr[i] = (i-1)*(derr[i-2]+derr[i-1]);
    
    int T,N;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        printf("%lld\n",derr[N]);
    }
    
    return 0;
}
