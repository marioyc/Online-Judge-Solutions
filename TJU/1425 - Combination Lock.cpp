#include <cstdio>

using namespace std;

int main(){
    int x0,x1,x2,x3,S;
    
    while(1){
        scanf("%d %d %d %d",&x0,&x1,&x2,&x3);
        if(x0==0 && x1==0 && x2==0 && x3==0) break;
        
        S=0;
        S+=x1>x0? x0+40-x1:x0-x1;
        S+=x2>x1? x2-x1:40-x1+x2;
        S+=x3>x2? x2+40-x3:x2-x3;
        S=S*9+1080;
        
        printf("%d\n",S);
    }
}
