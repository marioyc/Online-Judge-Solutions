#include<iostream>
#include<cmath>

#define PI acos(-1)

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int D,V;
    
    double d;
    
    while(1){
        scanf("%d %d",&D,&V);
        
        
        if(D==0 && V==0) break;
        
        d=pow(D*D*D-6*V/PI,1.0/3);
        
        printf("%.3f\n",d);
    }
}
