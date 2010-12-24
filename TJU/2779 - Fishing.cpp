#include <cstdio>

using namespace std;

int main(){
    int T,x1,y1,x2,y2,x,y,r;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        scanf("%d %d %d",&x,&y,&r);
        
        if(x-r>=x1 && x+r<=x2 && y-r>=y1 && y+r<=y2) puts("Just do it");
        else puts("Don't get close to it");
    }
    
    return 0;
}
