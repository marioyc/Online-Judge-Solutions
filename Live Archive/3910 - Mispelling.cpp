#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int T,N;
    char s[81];
    
    scanf("%d",&T);
    
    for(int tc = 1;tc<=T;++tc){
        scanf("%d %s",&N,s);
        int L = strlen(s);
        
        printf("%d ",tc);
        
        for(int i = 0;i<L;++i)
            if(i+1!=N) putchar(s[i]);
        
        putchar('\n');
    }
    
    return 0;
}
