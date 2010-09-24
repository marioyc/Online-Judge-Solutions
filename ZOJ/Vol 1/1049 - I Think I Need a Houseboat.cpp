#include<iostream>
#include<cmath>

#define PI acos(-1)

using namespace std;

int main(){
    int T,year;
    double x,y;
    
    scanf("%d",&T);
    
    for(int i=1;i<=T;i++){
        scanf("%lf %lf",&x,&y);
        
        year=ceil(PI/100*(x*x+y*y));
        
        printf("Property %d: This property will begin eroding in year %d.\n",i,year); 
    }
    printf("END OF OUTPUT.\n");
    
    return 0;
}
