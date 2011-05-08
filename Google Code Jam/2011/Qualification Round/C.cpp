#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T,N,C[1000];
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d",&N);
        
        int aux = 0;
        
        for(int i = 0;i < N;++i){
            scanf("%d",&C[i]);
            aux ^= C[i];
        }
        
        printf("Case #%d: ",tc);
        
        if(aux != 0) puts("NO");
        else{
            long long ans = 0;
            sort(C,C+N);
            
            for(int i = 1;i < N;++i) ans += C[i];
            
            printf("%lld\n",ans);
        }
    }
    
    return 0;
}
