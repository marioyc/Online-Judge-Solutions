#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N,b[100000];
    
    while(true){
        scanf("%d",&N);
        
        if(N == 0) break;
        
        long long ans = 1,aux = 1;
        
        for(int i = 0;i < N;++i){
            scanf("%d",&b[i]);
            ans *= b[i];
        }
        
        for(int i = 0,j = N - 1;i <= j;++i,--j)
            aux *= min(b[i],b[j]);
        
        printf("%lld\n",ans - aux);
    }
    
    return 0;
}
