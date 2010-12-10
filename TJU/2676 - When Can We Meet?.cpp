#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int N,Q,M;
    int cont[101];
    
    while(true){
        scanf("%d %d",&N,&Q);
        if(N==0 && Q==0) break;
        
        memset(cont,0,sizeof(cont));
        
        for(int i = 0;i<N;++i){
            scanf("%d",&M);
            
            for(int j = 0,d;j<M;++j){
                scanf("%d",&d);
                ++cont[d];
            }
        }
        
        int ans = 0;
        
        for(int i = 1;i<=100;++i)
            if(cont[i]>=Q && cont[i]>cont[ans])
                ans = i;
        
        printf("%d\n",ans);
    }
    
    return 0;
}
