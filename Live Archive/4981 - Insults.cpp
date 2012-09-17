#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

#define MAXL 1000001

char s[MAXL];
int S[MAXL],sz;

int main(){
    char alph[4];
    alph[0] = 'a';
    alph[1] = 'e';
    alph[2] = 'i';
    alph[3] = 'o';
    
    int T,L;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%s",s);
        
        L = strlen(s);
        
        bool valid = true;
        int pos = -1;
        char add;
        sz = 0;
        
        for(int i = 0;i < L && valid;++i){
            int tmp = sz;
            
            for(int j = 1;j < 4;++j){
                if(alph[j] > s[i]){
                    sz = tmp;
                    
                    if(alph[j] == 'i') ++sz;
                    else if(sz == 0 || (alph[j] =='e' && S[sz - 1] != 'a') || (alph[j] == 'o' && S[sz - 1] != 'i')) continue;
                    else --sz;
                    
                    if(L - 1 - i >= sz){
                        pos = i, add = alph[j];
                        break;
                    }
                }
            }
            
            sz = tmp;
            
            if(s[i] == 'a' || s[i] == 'i') S[sz++] = s[i];
            else if(sz == 0 || (s[i] =='e' && S[sz - 1] != 'a') || (s[i] == 'o' && S[sz - 1] != 'i')) valid = false;
            else --sz;
        }
        
        if(!valid || sz) puts("INVALID");
        else if(pos == -1) puts("ULTIMATE");
        else{
            s[pos] = add;
            
            for(int i = 0;i <= pos;++i) putchar(s[i]);
            
            for(int i = 0;i <= pos;++i){
                if(s[i] == 'a' || s[i] == 'i') S[sz++] = s[i];
                else --sz;
            }
            
            int ae = (L - sz - pos - 1) / 2;
            
            for(int i = 0;i < ae;++i) putchar('a');
            for(int i = 0;i < ae;++i) putchar('e');
            
            while(sz){
                --sz;
                putchar(S[sz] == 'a'? 'e' : 'o');
            }
            
            putchar('\n');
        }
    }
    
    return 0;
}
