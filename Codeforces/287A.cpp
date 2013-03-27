#include <cstdio>

using namespace std;

int main(){
    char M[4][5];
    
    for(int i = 0;i < 4;++i)
        scanf("%s",M[i]);
    
    for(int i = 0;i < 3;++i){
        for(int j = 0;j < 3;++j){
            int cont = (M[i][j] == '#'? 1 : 0) + (M[i + 1][j] == '#'? 1 : 0) + (M[i][j + 1] == '#'? 1 : 0) + (M[i + 1][j + 1] == '#'? 1 : 0);
            if(cont != 2){
                puts("YES");
                return 0;
            }
        }
    }
    
    puts("NO");
    
    return 0;
}
