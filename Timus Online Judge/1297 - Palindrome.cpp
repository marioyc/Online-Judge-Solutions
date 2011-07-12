#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    char s[1001];
    int L,best = 1,pos = 0;
    
    scanf("%s",s);
    L = strlen(s);
    
    for(int i = 1;i < L;++i){
        int cont = 0;
        
        for(int j = 1;i-j >= 0 && i+j < L;++j){
            if(s[i-j] == s[i+j]) ++cont;
            else break;
        }
        
        int l = 2 * cont + 1;
        
        if(l > best){
            best = l;
            pos = i - cont;
        }
    }
    
    for(int i = 0;i+1 < L;++i){
        if(s[i] == s[i+1]){
            int cont = 0;
            
            for(int j = 1;i-j >= 0 && i+1+j < L;++j){
                if(s[i-j] == s[i+1+j]) ++cont;
                else break;
            }
            
            int l = 2 * cont + 2;
            
            if(l > best || (l == best && i - cont < pos)){
                best = l;
                pos = i - cont;
            }
        }
    }
    
    for(int i = 0;i < best;++i) putchar(s[pos + i]);
    putchar('\n');
    
    return 0;
}
