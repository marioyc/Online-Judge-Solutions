#include <cstdio>

using namespace std;

int main(){
    int T,C,D;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&C,&D);
        
        if((D & C) != C) puts("-1");
        else{
            int A = 0,B = 0;
            
            A |= C;
            B |= C;
            D ^= C;
            
            if(D != 0){
                bool first = true;
                
                for(int i = 30;i >= 0;--i){
                    if(D & (1 << i)){
                        if(first) B ^= (1 << i);
                        else A ^= (1 << i);
                        first = false;
                    }
                }
            }
            
            printf("%d %d\n",A,B);
        }
    }
    
    return 0;
}
