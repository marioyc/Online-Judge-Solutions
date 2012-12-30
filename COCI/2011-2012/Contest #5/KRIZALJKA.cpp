#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    char a[31],b[31];
    
    scanf("%s %s",a,b);
    
    int la = strlen(a),lb = strlen(b);
    
    int inb[26];
    memset(inb,-1,sizeof inb);
    
    for(int i = 0;i < lb;++i)
        if(inb[ b[i] - 'A' ] == -1)
            inb[ b[i] - 'A' ] = i;
    
    char M[lb][la + 1];
    memset(M,0,sizeof M);
    
    for(int i = 0;i < lb;++i)
        for(int j = 0;j < la;++j)
            M[i][j] = '.';
    
    for(int i = 0;i < la;++i){
        if(inb[ a[i] - 'A' ] != -1){
            int r = inb[ a[i] - 'A' ];
            
            for(int j = 0;j < lb;++j)
                M[j][i] = b[j];
            for(int j = 0;j < la;++j)
                M[r][j] = a[j];
            
            break;
        }
    }
    
    for(int i = 0;i < lb;++i) puts(M[i]);
    
    return 0;
}
