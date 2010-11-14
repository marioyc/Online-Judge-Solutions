#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int N,cont[7][256];
    char c;
    
    while(scanf("%d",&N)==1){
        N = 2*N-1;
        c = getchar();
        
        memset(cont,0,sizeof(cont));
        
        for(int i = 0;i<N;++i){
            for(int j = 0;j<7;++j){
                c = getchar();
                cont[j][(int)c] ^= 1;
            }
            c = getchar();
        }
        
        for(int i = 0;i<7;++i)
            for(int j = 0;j<256;++j)
                if(cont[i][j]==1)
                    putchar((char)j);
        
        putchar('\n');
    }
    
    return 0;
}
