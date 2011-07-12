#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int calc(int v, int t){
    return ceil(t + 4.5 * 3600 / v);
}

int main(){
    int N,v,t;
    
    while(true){
        scanf("%d",&N);
        if(N == 0) break;
        
        int ans = -1;
        
        for(int i = 0;i < N;++i){
            scanf("%d %d",&v,&t);
            
            if(t >= 0){
                if(ans == -1) ans = calc(v,t);
                else ans = min(ans,calc(v,t));
            }
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
