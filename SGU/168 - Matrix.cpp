#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int R,C;
    
    scanf("%d %d",&R,&C);
    
    int M[R][C];
    
    for(int i = 0;i < R;++i){
        for(int j = 0;j < C;++j){
            scanf("%d",&M[i][j]);
            
            if(i > 0 && j + 1 < C)
                M[i][j] = min(M[i][j],M[i - 1][j + 1]);
        }
    }
    
    for(int j = C - 2;j >= 0;--j)
        M[R - 1][j] = min(M[R - 1][j],M[R - 1][j + 1]);
    
    for(int i = R - 2;i >= 0;--i)
        for(int j = C - 1;j >= 0;--j)
            M[i][j] = min(M[i][j],M[i + 1][j]);
    
    for(int i = 0;i < R;++i){
        for(int j = 0;j < C;++j) printf("%d ",M[i][j]);
        printf("\n");
    }
    
    return 0;
}
