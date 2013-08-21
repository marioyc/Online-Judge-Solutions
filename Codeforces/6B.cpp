#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int R,C;
    char s[2],M[100][101];
    int dr[] = {-1,1,0,0},dc[] = {0,0,-1,1};
    
    scanf("%d %d %s",&R,&C,s);
    
    for(int i = 0;i < R;++i)
        scanf("%s",M[i]);
    
    bool used[26];
    memset(used,false,sizeof used);
    
    for(int i = 0;i < R;++i){
        for(int j = 0;j < C;++j){
            if(M[i][j] == s[0]){
                for(int k = 0;k < 4;++k){
                    int r2 = i + dr[k],c2 = j + dc[k];
                    
                    if(r2 >= 0 && r2 < R && c2 >= 0 && c2 < C && M[r2][c2] != s[0] && M[r2][c2] != '.')
                        used[ M[r2][c2] - 'A' ] = true;
                }
            }
        }
    }
    
    int ans = 0;
    for(int i = 0;i < 26;++i)
        if(used[i]) ++ans;
    printf("%d\n",ans);
    
    return 0;
}
