#include <cstdio>
#include <cstring>

using namespace std;

int R,C,M2[15][15];

void flip(int r, int c){
    M2[r][c] ^= 1;
    if(r > 0) M2[r - 1][c] ^= 1;
    if(c > 0) M2[r][c - 1] ^= 1;
    if(c + 1 < C) M2[r][c + 1] ^= 1;
    if(r + 1 < R) M2[r + 1][c] ^= 1;
}

int main(){
    scanf("%d %d",&R,&C);
    
    int M[R][C];
    
    for(int i = 0;i < R;++i)
        for(int j = 0;j < C;++j)
            scanf("%d",&M[i][j]);
    
    int best = R * C + 1;
    int aux[R][C],ans[R][C];
    
    for(int mask = 0;mask < (1 << C);++mask){
        memset(aux,0,sizeof aux);
        int cont = 0;
        
        for(int i = 0;i < R;++i)
            for(int j = 0;j < C;++j)
                M2[i][j] = M[i][j];
        
        for(int i = 0;i < C;++i){
            if(mask & (1 << i)){
                flip(0,C - 1 - i);
                aux[0][C - 1 - i] = 1;
                ++cont;
            }
        }
        
        for(int i = 1;i < R;++i){
            for(int j = 0;j < C;++j){
                if(M2[i - 1][j]){
                    flip(i,j);
                    aux[i][j] = 1;
                    ++cont;
                }
            }
        }
        
        bool ok = true;
        
        for(int i = 0;i < C;++i)
            if(M2[R - 1][i]) ok = false;
        
        if(ok && cont < best){
            best = cont;
            
            for(int i = 0;i < R;++i)
                for(int j = 0;j < C;++j)
                    ans[i][j] = aux[i][j];
        }
    }
    
    if(best == R * C + 1) puts("IMPOSSIBLE");
    else{
        for(int i = 0;i < R;++i){
            for(int j = 0;j < C;++j){
                if(j > 0) putchar(' ');
                printf("%d",ans[i][j]);
            }
            
            putchar('\n');
        }
    }
    
    return 0;
}
