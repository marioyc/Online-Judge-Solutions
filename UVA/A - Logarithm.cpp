#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    int n,L;
    double x;
    
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        
        L=ceil(log(n/2.0));
        x=1-n/exp(L);
        
        printf("%d %.8f\n",L,x);
    }
    
    return 0;
}
