#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    double phi = (1+sqrt(5))/2;
    long long x,y;
    
    while(true){
        scanf("%lld %lld",&x,&y);
        if(x==0 && y==0) break;
        
        if(x>y){
            x ^= y;
            y ^= x;
            x ^= y;
        }
        
        if(y==x || y>phi*x) puts("Stan wins");
        else puts("Ollie wins");
    }
    
    return 0;
}
