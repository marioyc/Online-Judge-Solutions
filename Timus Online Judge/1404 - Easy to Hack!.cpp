#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    char s[101],ans[101];
    
    scanf("%s",s);
    
    int L = strlen(s);
    memset(ans,0,sizeof(ans));
    
    for(int i = L-1;i > 0;--i){
        int aux = s[i] - s[i-1];
        
        aux %= 26;
        if(aux < 0) aux += 26;
        
        ans[i] = 'a' + aux;
    }
    
    int aux = s[0] - 'a' - 5;
    aux %= 26;
    if(aux < 0) aux += 26;
    
    ans[0] = 'a' + aux;
    
    puts(ans);
    
    return 0;
}
