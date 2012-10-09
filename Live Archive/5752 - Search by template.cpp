#include <cstdio>
#include <cstring>

using namespace std;

#define MAXLEN 1000001
#define f(x) ((x) >= 'a' && (x) <= 'z'? (x) - 'a' : (x) - 'A' + 26)

int L1,L2;
bool ok[100][52];
char s[101],s2[MAXLEN];

int main(){
    int T;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%s %s",s,s2);
        
        L1 = strlen(s);
        L2 = strlen(s2);
        
        int m = 0;
        
        for(int i = 0;i < L1;){
            if(s[i] == '?'){
                memset(ok[m],true,sizeof ok[m]);
                ++i;
            }else if(s[i] == '['){
                memset(ok[m],false,sizeof ok[m]);
                int e = i + 1;
                
                while(e < L1){
                    if(s[e] == ']') break;
                    ok[m][ f(s[e]) ] = true;
                    ++e;
                }
                
                i = e + 1;
            }else if(s[i] == '{'){
                memset(ok[m],true,sizeof ok[m]);
                int e = i + 1;
                
                while(e < L1){
                    if(s[e] == '}') break;
                    ok[m][ f(s[e]) ] = false;
                    ++e;
                }
                
                i = e + 1;
            }else{
                memset(ok[m],false,sizeof ok[m]);
                ok[m][ f(s[i]) ] = true;
                ++i;
            }
            
            ++m;
        }
        
        bool found = false;
        
        for(int i = 0;i + m <= L2;++i){
            bool match = true;
            
            for(int j = 0;j < m;++j)
                if(!ok[j][ f(s2[i + j]) ]){
                    match = false;
                }
            
            if(match){
                if(found) putchar(' ');
                found = true;
                printf("%d",i + 1);
            }
        }
        
        if(!found) puts("no match");
        else putchar('\n');
    }
    
    return 0;
}
