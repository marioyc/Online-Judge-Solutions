#include <cstdio>

using namespace std;

int main(){
    int T,n;
    char M[10][11];
    
    int dr[] = {-1,1,0,0};
    int dc[] = {0,0,-1,1};
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d",&n);
        
        for(int i = 0;i < n;++i)
            scanf("%s",M[i]);
        
        for(int i = 0;i < n;++i){
            for(int j = 0;j < n;++j){
                if(M[i][j] == '.'){
                    for(char c = 'A';c <= 'Z';++c){
                        bool ok = true;
                        
                        for(int k = 0;k < 4;++k){
                            int i2 = i + dr[k];
                            int j2 = j + dc[k];
                            
                            if(i2 >= 0 && i2 < n && j2 >= 0 && j2 < n && M[i2][j2] == c)
                                ok = false;
                        }
                        
                        if(ok){
                            M[i][j] = c;
                            break;
                        }
                    }
                }
            }
        }
        
        printf("Case %d:\n",tc);
        
        for(int i = 0;i < n;++i) puts(M[i]);
    }
    
    return 0;
}
