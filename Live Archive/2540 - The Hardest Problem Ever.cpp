#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    char s[205];
    
    while(true){
        fgets(s,205,stdin);
        if(s[0]=='E') break;
        
        fgets(s,205,stdin);
        int L = strlen(s)-1;
        
        for(int i = 0;i<L;++i){
            if(s[i]>='A' && s[i]<='Z') putchar((char)('A'+(s[i]-'A'+21)%26));
            else putchar(s[i]);
        }
        
        putchar('\n');
        
        fgets(s,205,stdin);
    }
    
    return 0;
}
