#include <cstdio>

using namespace std;

int main(){
    int T,a,m;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&a,&m);
        
        int ans = -1;
        
        for(int i = 1;i <= m;++i)
            if((a * i - 1) % m == 0){
                ans = i;
                break;
            }
        
        if(ans == -1) puts("Not Exist");
        else printf("%d\n",ans);
    }
    
    return 0;
}
