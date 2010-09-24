#include<cstdio>
#include<algorithm>

using namespace std;

struct point{
    char c;
    int x,y;
    
    point(){
    }
    
    point(char _c, int _x, int _y){
        c=_c;
        x=_x;
        y=_y;
    }    
};

int main(){    
    int n,set=1,cont;
    point a[26];
    point P;
    
    while(1){
        scanf("%d\n",&n);
        if(n==0) break;        
        
        for(int i=0;i<n;i++){
            scanf("%c %d %d\n",&P.c,&P.x,&P.y);
            a[i]=P;
        }
        
        printf("Point set %d:",set);
        set++;
        
        cont=0;
        
        for(int i1=0;i1<n;i1++){
            for(int i2=0;i2<n;i2++){
                if(a[i1].y!=a[i2].y || a[i1].x>=a[i2].x) continue;
                
                for(int i3=0;i3<n;i3++){
                    if(a[i2].x!=a[i3].x || a[i2].y<=a[i3].y) continue;
                    for(int i4=0;i4<n;i4++){
                        if(a[i3].y!=a[i4].y || a[i3].x<=a[i4].x) continue;
                        if(a[i4].x!=a[i1].x || a[i4].y>=a[i1].y) continue;
                        if(cont%10==0) printf("\n");
                        
                        printf(" %c%c%c%c",a[i1].c,a[i2].c,a[i3].c,a[i4].c);
                        
                        cont++;
                    }
                }
            }
        }
        
        if(cont==0) printf(" No rectangles");
        
        printf("\n");
    }
    
    return 0;
}
