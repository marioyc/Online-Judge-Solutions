#include <cstdio>

using namespace std;

int main(){
    int T;
    char M[5][6];
    
    scanf("%d",&T);
    
    while(T--){
        for(int i = 0;i < 5;++i)
            scanf("%s",M[i]);
        
        int ans = 0;
        
        for(int i = 0;i < 5;++i){
            for(int j = 0;j < 5;++j){
                if(i < 3 && M[i + 1][j] == M[i][j] && M[i + 2][j] == M[i][j])
                    ans |= (1 << (M[i][j] == 'A'? 0 : 1));
                
                if(j < 3 && M[i][j + 1] == M[i][j] && M[i][j + 2] == M[i][j])
                    ans |= (1 << (M[i][j] == 'A'? 0 : 1));
                
                if(i < 3 && j < 3 && M[i + 1][j + 1] == M[i][j] && M[i + 2][j + 2] == M[i][j])
                    ans |= (1 << (M[i][j] == 'A'? 0 : 1));
                
                if(i < 3 && j > 1 && M[i + 1][j - 1] == M[i][j] && M[i + 2][j - 2] == M[i][j])
                    ans |= (1 << (M[i][j] =='A'? 0 : 1));
            }
        }
        
        if(ans == 0 || ans == 3) puts("draw");
        else if(ans == 1) puts("A wins");
        else puts("B wins");
    }
    
    return 0;
}
