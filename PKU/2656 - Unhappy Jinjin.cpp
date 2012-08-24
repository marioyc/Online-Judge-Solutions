#include <cstdio>

using namespace std;

int main(){
    int N;
    
    while(true){
        scanf("%d",&N);
        
        if(N == 0) break;
        
        int best = 0,ans = 0;
        
        for(int i = 1,a,b;i <= N;++i){
            scanf("%d %d",&a,&b);
            a += b;
            
            if(a > best){
                best = a;
                ans = i;
            }
        }
        
        if(best <= 8) puts("0");
        else printf("%d\n",ans);
    }
    
    return 0;
}
