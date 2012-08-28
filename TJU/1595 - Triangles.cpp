#include <cstdio>
#include <algorithm>

using namespace std;

char s[100][200];
bool ok[100][200][200];

int main(){
    int tc = 1,n;
    
    while(true){
        scanf("%d",&n);
        if(n == 0) break;
        
        for(int i = n - 1;i >= 0;--i)
            scanf("%s",s[i]);
        
        for(int i = 0,L = 1;i < n;++i,L += 2){
            for(int j = L - 1;j >= 0;--j)
                ok[i][j][1] = (s[i][j] == '#'? false : true);
            
            for(int j = L - 1;j >= 0;--j)
                for(int k = 2;j + k <= L;++k)
                    ok[i][j][k] = ok[i][j][1] && ok[i][j + 1][k - 1];
        }
        
        int ans = 0;
        
        for(int i = 0;i < n;++i){
            for(int j = 2 * i;j >= 0;j -= 2){
                if(ok[i][j][1]){
                    int aux = 1;
                    
                    for(int k = 2,L = 3;i + k <= n;++k,L += 2){
                        if(ok[i + k - 1][j][L]) ++aux;
                        else break;
                    }
                    
                    ans = max(ans,aux);
                }
            }
            
            for(int j = 2 * i - 1;j >= 0;j -= 2){
                if(ok[i][j][1]){
                    int aux = 1;
                    
                    for(int k = 2,L = 3;i - k + 1 >= 0 && j >= 2 * (k - 1) && j - 2 * (k - 1) + L <= 2 * (i - k + 1) + 1;++k,L += 2){
                        if(ok[i - k + 1][j - 2 * (k - 1)][L]) ++aux;
                        else break;
                    }
                    
                    ans = max(ans,aux);
                }
            }
        }
        
        printf("Triangle #%d\nThe largest triangle area is %d.\n\n",tc++,ans * ans);
    }
    
    return 0;
}
