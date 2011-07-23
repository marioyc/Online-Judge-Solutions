#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int n,x;
    
    scanf("%d %d",&n,&x);
    
    int x1 = -1000,x2 = 1000;
    
    for(int i = 0,aux;i < n;++i){
        scanf("%d",&aux);
        
        if(aux < 0) x1 = max(x1,aux);
        if(aux > 0) x2 = min(x2,aux);
    }
    
    if(x1 < x && x < x2){
        if(x > 0) printf("%d %d\n",x,-x1 + x - x1);
        else printf("%d %d\n",x2 + x2 - x,-x);
    }else puts("Impossible");
    
    return 0;
}
