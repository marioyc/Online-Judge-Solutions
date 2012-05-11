#include <cstdio>

using namespace std;

int main(){
    int T,N;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        int ans = -1;
        
        for(int y = 0;4*y <= N && ans == -1;++y)
            if((N - 4*y) % 7 == 0)
                ans = N - 4*y;
        
        printf("%d\n",ans);
    }
    
    return 0;
}
