#include <cstdio>

using namespace std;

#define min(a,b) ((a)<(b)? (a) : (b))

int main(){
    int N;
    
    while(true){
        scanf("%d",&N);
        if(N==0) break;
        
        int odds[2],evens[2];
        
        for(int i = 0,x;i<2;++i){
            odds[i] = evens[i] = 0;
            
            for(int j = 0;j<N;++j){
                scanf("%d",&x);
                if(x & 1) ++odds[i];
                else ++evens[i];
            }
        }
        
        printf("%d\n",N-min(odds[0],evens[1])-min(evens[0],odds[1]));
    }
    
    return 0;
}
