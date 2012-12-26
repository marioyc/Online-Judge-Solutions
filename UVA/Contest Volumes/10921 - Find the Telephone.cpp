#include <cstdio>
#include <cstring>

using namespace std;

char f(char c){
    if(c == '0' || c == '1' || c == '-') return c;
    if(c <= 'C') return '2';
    if(c <= 'F') return '3';
    if(c <= 'I') return '4';
    if(c <= 'L') return '5';
    if(c <= 'O') return '6';
    if(c <= 'S') return '7';
    if(c <= 'V') return '8';
    return '9';
}

int main(){
    char s[31];
    
    while(scanf("%s",s) == 1){
        int L = strlen(s);
        
        for(int i = 0;i < L;++i) putchar(f(s[i]));
        putchar('\n');
    }
    
    return 0;
}
