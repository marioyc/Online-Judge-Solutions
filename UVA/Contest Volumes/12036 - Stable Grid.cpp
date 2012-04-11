#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int tc = 1,T,n,x,cont[101];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&n);
        
        memset(cont,0,sizeof cont);
        
        for(int i = 0;i < n;++i){
            for(int j = 0;j < n;++j){
                scanf("%d",&x);
                ++cont[x];
            }
        }
        
        bool ok = true;
        
        for(int i = 0;i <= 100;++i)
            if(cont[i] > n) ok = false;
        
        printf("Case %d: %s\n",tc++,ok? "yes" : "no");
    }
    
    return 0;
}
