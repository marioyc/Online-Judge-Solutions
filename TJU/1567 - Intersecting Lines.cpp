#include <cstdio>

using namespace std;

int main(){
    int T,x1,y1,x2,y2,x3,y3,x4,y4;
    scanf("%d",&T);
    
    puts("INTERSECTING LINES OUTPUT");
    
    while(T--){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        scanf("%d %d %d %d",&x3,&y3,&x4,&y4);
        
        if((y2-y1)*(x4-x3)==(y4-y3)*(x2-x1)){
            if((y4-y1)*(x4-x3)==(y4-y3)*(x4-x1)) puts("LINE");
            else puts("NONE");
        }else{
            if(x2==x1){
                double m2 = (double)(y4-y3)/(x4-x3);
                double y = m2*(x1-x4)+y4;
                
                printf("POINT %d.00 %.2f\n",x1,y);
            }else if(x4==x3){
                double m1 = (double)(y2-y1)/(x2-x1);
                double y = m1*(x4-x1)+y1;
                
                printf("POINT %d.00 %.2f\n",x4,y);
            }else{
                double m1 = (double)(y2-y1)/(x2-x1);
                double m2 = (double)(y4-y3)/(x4-x3);
                
                double x = (y4-y1-m2*x4+m1*x1)/(m1-m2);
                double y = m1*(x-x1)+y1;
                
                printf("POINT %.2f %.2f\n",x,y);
            }
        }
    }
    
    puts("END OF OUTPUT");
    
    return 0;
}
