#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T,N,X,Y,a[100];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d %d",&N,&X,&Y);
        
        for(int i = 0;i<N;++i) scanf("%d",&a[i]);
        
        int ans = 0;
        for(int i = 0;i<N-X-Y;++i) ans += a[i];
        
        for(int i = 0;i+X+Y<=N;++i){
            for(int j = i+X;j+Y<=N;++j){
                int aux = 0;
                for(int k = 0;k<i;++k) aux += a[k];
                for(int k = i+X;k<j;++k) aux += a[k];
                for(int k = j+Y;k<N;++k) aux += a[k];
                ans = max(ans,aux);
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
