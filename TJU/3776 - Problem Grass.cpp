#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T,R,C,M[100][100],ans;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&R,&C);
        
        for(int i = 0;i<R;++i)
            for(int j = 0;j<C;++j)
                scanf("%d",&M[i][j]);
        
        for(int i = 0;i<R;++i)
            for(int j = 1;j<C;++j)
                M[i][j] += M[i][j-1];
        
        ans = 0;
        
        for(int i = 0;i<C;++i) for(int j = i;j<C;++j){
            int best = 0;
            
            for(int k = 0;k<R;++k){
                int aux = M[k][j]-(i>0? M[k][i-1] : 0);
                
                if(best+aux>=0){
                    ans = max(ans,best+aux);
                    best += aux;
                }else best = 0;
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
