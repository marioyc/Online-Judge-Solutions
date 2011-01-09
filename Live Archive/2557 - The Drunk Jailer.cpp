#include <cstdio>

using namespace std;

int main(){
    int T,N;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        int lo = 0,hi = N,mi;
        
        while(lo<hi){
            mi = (lo+hi+1)>>1;
            
            if(mi*mi>N) hi = mi-1;
            else lo = mi;
        }
        
        printf("%d\n",hi);
    }
    
    return 0;
}
