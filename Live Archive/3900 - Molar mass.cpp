#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int T,L;
    char s[81];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%s",s);
        L = strlen(s);
        
        double ans = 0;
        
        for(int i = 0;i < L;){
            int aux = 0,j = i + 1;
            
            while(j < L && s[j] >= '0' && s[j] <= '9'){
                aux = aux * 10 + s[j] - '0';
                ++j;
            }
            
            if(aux == 0) aux = 1;
            
            if(s[i] == 'C') ans += 12.01 * aux;
            if(s[i] == 'H') ans += 1.008 * aux;
            if(s[i] == 'O') ans += 16 * aux;
            if(s[i] == 'N') ans += 14.01 * aux;
            
            i = j;
        }
        
        printf("%.3f\n",ans);
    }
    
    return 0;
}
