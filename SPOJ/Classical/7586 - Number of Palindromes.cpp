#include <cstdio>
#include <cstring>

using namespace std;

#define MAXLEN 1000

int L;
char s[MAXLEN + 1];

int main(){
    scanf("%s",s);
    L = strlen(s);
    
    int ans = 0;
    
    for(int i = 0;i < L;++i){
        int aux = 0;
        
        while(i - aux >= 0 && i + aux < L && s[i - aux] == s[i + aux]) ++aux;
        
        ans += aux;
    }
    
    for(int i = 0;i + 1 < L;++i){
        int aux = 0;
        
        while(i - aux >= 0 && i + 1 + aux < L && s[i - aux] == s[i + 1 + aux]) ++aux;
        
        ans += aux;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
