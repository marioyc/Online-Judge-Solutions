#include <cstdio>

using namespace std;

int main(){
    int T,N;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        int ans = 0;
        
        for(int i = 0,id,sum;i < N;++i){
            scanf("%d %d",&id,&sum);
            ans += id - sum;
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
