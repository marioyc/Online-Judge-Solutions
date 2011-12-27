#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int N,M[1001][1001];
    bool win[1001][1001];
    
    while(scanf("%d",&N) == 1){
        memset(M,0,sizeof M);
        
        for(int i = 1,aux;i <= N;++i){
            for(int j = 1;j <= N;++j){
                scanf("%d",&aux);
                
                M[i][j] = (aux % 2 == 1? 1 : 0) ^ M[i][j - 1] ^ M[i - 1][j] ^ M[i - 1][j - 1];
            }
        }
        
        for(int i = 1;i <= N;++i){
            for(int j = 1;j <= N;++j){
                win[i][j] = false;
                
                if((M[i][j] ^ M[i - 1][j]) == 0 && !win[i - 1][j]) win[i][j] = true;
                if((M[i][j] ^ M[i][j - 1]) == 0 && !win[i][j - 1]) win[i][j] = true;
            }
        }
        
        puts(win[N][N]? "W" : "L");
    }
    
    return 0;
}
