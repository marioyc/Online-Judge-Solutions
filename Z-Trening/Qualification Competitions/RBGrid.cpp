#include <cstdio>

using namespace std;

char M[1000][1001];

int main(){
    int R,C;
    
    scanf("%d %d",&R,&C);
    
    for(int i = 0;i < R;++i)
        scanf("%s",M[i]);
    
    int ans = 0;
    
    for(int i = 1;i+1 < R;++i)
        for(int j = 1;j+1 < C;++j)
            if(M[i][j] == 'B' && M[i-1][j] == 'B' && M[i+1][j] == 'B' && M[i][j-1] == 'B' && M[i][j+1] == 'B')
                ++ans;
    
    printf("%d\n",ans);
    
    return 0;
}
