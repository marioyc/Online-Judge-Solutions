#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int T,tc,cont[2][2][2];
    char s[41];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&tc);
        scanf("%s",s);
        
        memset(cont,0,sizeof cont);
        
        for(int i = 0;i < 38;++i)
            ++cont[s[i] == 'T'? 0 : 1][s[i + 1] == 'T'? 0 : 1][s[i + 2] == 'T'? 0 : 1];
        
        printf("%d",tc);
        
        for(int i = 0;i < 2;++i)
            for(int j = 0;j < 2;++j)
                for(int k = 0;k < 2;++k)
                    printf(" %d",cont[i][j][k]);
        
        printf("\n");
    }
    
    return 0;
}
