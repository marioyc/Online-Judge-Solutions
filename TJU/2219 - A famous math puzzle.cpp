#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N,W;
    
    while(true){
        scanf("%d %d",&N,&W);
        if(N==0 && W==0) break;
        
        int g;
        scanf("%d",&g);
        
        bool found = false;
        if(g>=W) found = true;
        
        for(int i = 1,x;i<N;++i){
            scanf("%d",&x);
            g = __gcd(g,x);
            if(x>=W) found = true;
        }
        
        if(found && W%g==0) puts("YES");
        else puts("NO");
    }
    
    return 0;
}
