#include <cstdio>

using namespace std;

bool change(char cur, char c1, char c2){
    if(cur == 'x' && c1 == '-') return true;
    if(cur == 'y' && c2 == 'y' && c1 == '+') return true;
    if(cur == 'z' && c2 == 'z' && c1 == '+') return true;
    return false;
}

int main(){
    int L;
    char s[3];
    
    while(true){
        scanf("%d",&L);
        if(L == 0) break;
        --L;
        
        int sign = 1;
        char c = 'x';
        
        for(int i = 0;i < L;++i){
            scanf("%s",s);
            if(s[0] == 'N') continue;
            
            if(change(c,s[0],s[1])) sign = -sign;
            
            if(c == 'x') c = s[1];
            else if(c == 'y' && s[1] == 'y') c = 'x';
            else if(c == 'z' && s[1] == 'z') c = 'x';
        }
        
        printf("%c%c\n",sign == 1? '+' : '-',c);
    }
    
    return 0;
}
