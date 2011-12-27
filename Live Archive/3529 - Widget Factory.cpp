#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n,m,M[300][301];
char s1[4],s2[4];

void solve(){
    int r = 0;
    
    for(int i = 0;i < n;++i){
        int ind = -1;
        
        for(int j = r;j < m && ind == -1;++j)
            if(M[j][i]) ind = j;
        
        if(ind != -1){
            for(int j = i;j <= n;++j)
                swap(M[r][j],M[ind][j]);
            
            int aux = M[r][i] * M[r][i] * M[r][i] * M[r][i] * M[r][i] % 7;
            
            for(int j = i;j <= n;++j)
                M[r][j] = M[r][j] * aux % 7;
            
            for(int j = r + 1;j < m;++j)
                for(int k = n;k >= i;--k)
                    M[j][k] = ((M[j][k] - M[j][i] * M[r][k]) % 7 + 7) % 7;
            
            ++r;
        }
    }
    
    for(int i = 0;i < m;++i){
        bool zero = true;
        
        for(int j = 0;j < n;++j)
            if(M[i][j] != 0) zero = false;
        
        if(zero && M[i][n] != 0){
            puts("Inconsistent data.");
            return;
        }
    }
    
    if(r < n){
        puts("Multiple solutions.");
        return;
    }
    
    for(int i = n - 1,aux;i >= 0;--i){
        for(int j = 0;j < i;++j){
            aux = M[j][i];
            
            for(int k = 0;k <= n;++k)
                M[j][k] = ((M[j][k] - aux * M[i][k]) % 7 + 7) % 7;
        }
        
        if(M[i][n] < 3) M[i][n] += 7;
    }
    
    for(int i = 0;i < n;++i){
        if(i > 0) putchar(' ');
        printf("%d",M[i][n]);
    }
    
    printf("\n");
}

int main(){
    while(true){
        scanf("%d %d",&n,&m);
        if(n == 0) break;
        
        memset(M,0,sizeof M);
        
        for(int i = 0,sz,x,y;i < m;++i){
            scanf("%d %s %s",&sz,s1,s2);
            
            if(s1[0] == 'M') x = 0;
            else if(s1[0] == 'T'){
                if(s1[1] == 'U') x = 1;
                else x = 3;
            }else if(s1[0] == 'W') x = 2;
            else if(s1[0] == 'F') x = 4;
            else{
                if(s1[1] == 'A') x = 5;
                else x = 6;
            }
            
            if(s2[0] == 'M') y = 0;
            else if(s2[0] == 'T'){
                if(s2[1] == 'U') y = 1;
                else y = 3;
            }else if(s2[0] == 'W') y = 2;
            else if(s2[0] == 'F') y = 4;
            else{
                if(s2[1] == 'A') y = 5;
                else y = 6;
            }
            
            for(int j = 0,aux;j < sz;++j){
                scanf("%d",&aux);
                --aux;
                ++M[i][aux];
                if(M[i][aux] == 7) M[i][aux] = 0;
            }
            
            M[i][n] = y - x + 1;
            
            if(M[i][n] >= 7) M[i][n] -= 7;
            if(M[i][n] < 0) M[i][n] += 7;
        }
        
        solve();
    }
    
    return 0;
}
