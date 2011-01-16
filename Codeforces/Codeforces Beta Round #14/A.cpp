#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int R,C;
    scanf("%d %d",&R,&C);
    
    char M[R][C+1];
    for(int i = 0;i<R;++i) scanf("%s",M[i]);
    
    int r1 = R-1,r2 = 0,c1 = C-1,c2 = 0;
    
    for(int i = 0;i<R;++i) for(int j = 0;j<C;++j){
        if(M[i][j]=='*'){
            r1 = min(r1,i);
            r2 = max(r2,i);
            c1 = min(c1,j);
            c2 = max(c2,j);
        }
    }
    
    for(int i = r1;i<=r2;++i){
        for(int j = c1;j<=c2;++j)
            putchar(M[i][j]);
        putchar('\n');
    }
    
    return 0;
}
