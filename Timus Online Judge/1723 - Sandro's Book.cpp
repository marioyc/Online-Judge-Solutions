#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    char s[51];
    
    scanf("%s",s);
    
    int L = strlen(s),cont[26];
    
    memset(cont,0,sizeof(cont));
    
    for(int i = 0;i < L;++i)
        ++cont[s[i] - 'a'];
    
    char ans = 'a';
    
    for(char c = 'b';c <= 'z';++c)
        if(cont[c - 'a'] > cont[ans - 'a'])
            ans = c;
    
    putchar(ans);
    
    return 0;
}
