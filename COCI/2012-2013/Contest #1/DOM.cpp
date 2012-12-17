#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    char s[101];
    
    scanf("%s",s);
    
    int L = strlen(s);
    
    for(int i = 0;i < L;++i)
        if(s[i] != 'C' && s[i] != 'A' && s[i] != 'M' && s[i] != 'B' && s[i] != 'R'
            && s[i] != 'I' && s[i] != 'D' && s[i] != 'G' && s[i] != 'E')
            printf("%c",s[i]);
    
    printf("\n");
    
    return 0;
}
