#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int T,L;
    char s[1001];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%s",s);
        
        L = strlen(s);
        
        for(int i = 0;i < L;){
            int cont = 0,e = i;
            
            while(e < L && s[e] == s[i]){
                ++cont;
                ++e;
            }
            
            printf("%d%c",cont,s[i]);
            
            i = e;
        }
        
        printf("\n");
    }
    
    return 0;
}
