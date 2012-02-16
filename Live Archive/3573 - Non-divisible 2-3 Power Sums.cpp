#include <cstdio>

using namespace std;

int main(){
    int T,N,a2[32],a3[32],sz;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d",&N);
        
        int exp2 = 0;
        sz = 0;
        
        while(N){
            if(N & 1){
                int exp3 = 0,pow3 = 1;
                
                while(pow3 <= N / 3){
                    pow3 *= 3;
                    ++exp3;
                }
                
                a2[sz] = exp2;
                a3[sz] = exp3;
                ++sz;
                
                N -= pow3;
            }
            
            N >>= 1;
            
            ++exp2;
        }
        
        printf("%d %d",tc,sz);
        
        for(int i = 0;i < sz;++i)
            printf(" [%d,%d]",a2[i],a3[i]);
        
        printf("\n");
    }
    
    return 0;
}
