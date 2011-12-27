#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N,ans,aux;
    
    while(true){
        scanf("%d",&N);
        if(N == 0) break;
        
        aux = 0;
        ans = -101;
        
        for(int i = 0,a;i < N;++i){
            scanf("%d",&a);
            
            aux = a + max(aux,0);
            ans = max(ans,aux);
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
