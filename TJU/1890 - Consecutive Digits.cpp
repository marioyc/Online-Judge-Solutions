#include <cstdio>

using namespace std;

int main(){
    int T,n,d,s,e;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc<=T;++tc){
        scanf("%d %d %d %d",&n,&d,&s,&e);
        printf("Problem set %d: %d / %d, base 7 digits %d through %d: ",tc,n,d,s,e);
        
        n %= d;
        
        for(int i = 0;i<=e;++i){
            n *= 7;
            if(i>=s){
                int aux = n/d;
                putchar('0'+aux);
            }
            n %= d;
        }
        
        putchar('\n');
    }
    
    return 0;
}
