#include <cstdio>

using namespace std;

int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    
    int d2 = x*x+y*y;
    int lo = 0,hi = 1414214,mi;
    
    while(lo!=hi){
        mi = (lo+hi+1)/2;
        
        if((long long)mi*mi>d2) hi = mi-1;
        else lo = mi;
    }
    
    if(x==0 || y==0 || lo*lo==d2) printf("black\n");
    else{
        if(x*y>=0){
            if(lo%2==1) printf("white\n");
            else printf("black\n");
        }else{
            if(lo%2==1) printf("black\n");
            else printf("white\n");
        }
    }
    
    return 0;
}
