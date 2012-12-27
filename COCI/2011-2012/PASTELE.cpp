#include <cstdio>
#include <algorithm>

using namespace std;

int cont[257][257][257],M[257][257][257];

int main(){
    int N,K;
    
    scanf("%d %d",&N,&K);
    
    for(int i = 0,r,g,b;i < N;++i){
        scanf("%d %d %d",&r,&g,&b);
        ++r; ++g; ++b;
        ++cont[r][g][b];
        ++M[r][g][b];
    }
    
    for(int i = 1;i <= 256;++i)
        for(int j = 1;j <= 256;++j)
            for(int k = 1;k <= 256;++k)
                M[i][j][k] += M[i - 1][j][k] + M[i][j - 1][k] + M[i][j][k - 1]
                    - M[i - 1][j - 1][k] - M[i - 1][j][k - 1] - M[i][j - 1][k - 1]
                    + M[i - 1][j - 1][k - 1];
    
    int lo = 0,hi = 255,mi;
    
    while(lo < hi){
        mi = (lo + hi) >> 1;
        
        int best = 0;
        
        for(int i = 1;i <= 256 - mi && best < K;++i)
            for(int j = 1;j <= 256 - mi && best < K;++j)
                for(int k = 1;k <= 256 - mi && best < K;++k){
                    int i2 = i + mi,j2 = j + mi,k2 = k + mi;
                    
                    int aux = M[i2][j2][k2] - M[i - 1][j2][k2] - M[i2][j - 1][k2] - M[i2][j2][k - 1]
                        + M[i - 1][j - 1][k2] + M[i - 1][j2][k - 1] + M[i2][j - 1][k - 1]
                        - M[i - 1][j - 1][k - 1];
                    
                    best = max(best,aux);
                }
        
        if(best < K) lo = mi + 1;
        else hi = mi;
    }
    
    printf("%d\n",lo);
    
    bool done = false;
    
    for(int i = 1;i <= 256 - lo && !done;++i)
        for(int j = 1;j <= 256 - lo && !done;++j)
            for(int k = 1;k <= 256 - lo && !done;++k){
                int i2 = i + lo,j2 = j + lo,k2 = k + lo;
                
                int aux = M[i2][j2][k2] - M[i - 1][j2][k2] - M[i2][j - 1][k2] - M[i2][j2][k - 1]
                    + M[i - 1][j - 1][k2] + M[i - 1][j2][k - 1] + M[i2][j - 1][k - 1]
                    - M[i - 1][j - 1][k - 1];
                
                if(aux >= K){
                    done = true;
                    
                    for(int x = 0;x <= lo;++x)
                        for(int y = 0;y <= lo;++y)
                            for(int z = 0;z <= lo;++z)
                                while(K && cont[i + x][j + y][k + z]){
                                    printf("%d %d %d\n",i - 1 + x,j - 1 + y,k - 1 + z);
                                    --cont[i + x][j + y][k + z];
                                    --K;
                                }
                }
            }
    
    return 0;
}
