#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int N;
    
    scanf("%d",&N);
    
    int mask = (1 << 26) - 1;
    char s[101];
    
    for(int i = 0;i < N;++i){
        scanf("%s",s);
        int L = strlen(s),aux = 0;
        
        for(int j = 0;j < L;++j)
            aux |= (1 << (s[j] - 'a'));
        
        mask &= aux;
    }
    
    printf("%d\n",__builtin_popcount(mask));
    
    return 0;
}
