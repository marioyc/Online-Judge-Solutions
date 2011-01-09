#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    char s[221];
    int L;
    
    while(true){
        fgets(s,220,stdin);
        L = strlen(s); --L;
        
        if(L==1) break;
        
        int pos = 0,turn = 0;
        bool neg = false;
        
        if(s[0]=='-'){
            neg = true;
            ++pos;
        }
        
        while(s[pos]!=':'){
            turn = turn*10+s[pos]-'0';
            ++pos;
        }
        
        if(neg) turn = -turn;
        ++pos;
        
        for(int i = pos;i<L;++i){
            if(s[i]>='A' && s[i]<='Z'){
                int x = s[i]-'A';
                x = ((x+turn)%26+26)%26;
                
                putchar('A'+x);
            }else if(s[i]>='a' && s[i]<='z'){
                int x = s[i]-'a';
                x = ((x+turn)%26+26)%26;
                
                putchar('a'+x);
            }else if(s[i]>='0' && s[i]<='9'){
                int x = s[i]-'0';
                x = ((x+turn)%10+10)%10;
                
                putchar('0'+x);
            }else putchar(s[i]);
        }
        
        putchar('\n');
    }
    
    return 0;
}
