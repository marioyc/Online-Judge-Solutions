#include <cstdio>

using namespace std;

int main(){
    int a,b,c,d;
    
    scanf("%d %d %d %d",&a,&b,&c,&d);
    
    int t = 0;
    
    while(true){
        if(a + b*t >= c - d*t){
            printf("%d\n",a + b*t);
            break;
        }
        
        if(c - d*t <= a + b*(t+1)){
            printf("%d\n",c - d*t);
            break;
        }
        
        ++t;
    }
    
    return 0;
}
