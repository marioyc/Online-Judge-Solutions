#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T,x1,y1,x2,y2,x3,y3,x4,y4;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d %d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        
        int X1 = max(x1,x3),X2 = min(x2,x4);
        int Y1 = max(y1,y3),Y2 = min(y2,y4);
        
        if(max(0,X2 - X1) * max(0,Y2 - Y1) == 0) puts("A and B do not overlap");
        else if(X1 == x1 && X2 == x2 && Y1 == y1 && Y2 == y2) puts("B surrounds A");
        else if(X1 == x3 && X2 == x4 && Y1 == y3 && Y2 == y4) puts("A surrounds B");
        else puts("A and B overlap");
    }
    
    return 0;
}
