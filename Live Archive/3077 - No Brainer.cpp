#include <cstdio>

using namespace std;

int main(){
    int T,X,Y;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&X,&Y);
        
        if(X>=Y) puts("MMM BRAINS");
        else puts("NO BRAINS");
    }
    
    return 0;
}
