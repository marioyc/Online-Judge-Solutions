#include <cstdio>

using namespace std;

int main(){
    int T,n;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&n);
        int pow10 = 10;
        
        while(n > pow10){
            int rem = n % pow10;
            
            if(rem >= pow10 / 2) n += pow10 - rem;
            else n -= rem;
            
            pow10 *= 10;
        }
        
        printf("%d\n",n);
    }
    
    return 0;
}
