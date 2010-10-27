#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    
    int w[20];
    for(int i = 0;i<N;++i)
        scanf("%d",&w[i]);
    
    int ans = 2000000;
    
    for(int i = (1<<(N-1))-1;i>=0;--i){
        int aux = 0;
        
        for(int j = 0;j<N;++j)
            if(i & (1<<j)) aux += w[j];
            else aux -= w[j];
        
        ans = min(ans,abs(aux));
    }
    
    printf("%d\n",ans);
    
    return 0;
}
