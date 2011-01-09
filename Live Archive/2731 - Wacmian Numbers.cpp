#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    char s[11];
    
    while(true){
        scanf("%s",s);
        if(s[0]=='#') break;
        
        int L = strlen(s),ans = 0;
        
        for(int i = L-1,p = 1;i>=0;--i,p *= 6){
            if(s[i]==')') ans += 1*p;
            else if(s[i]=='~') ans += 2*p;
            else if(s[i]=='@') ans += 3*p;
            else if(s[i]=='?') ans += 4*p;
            else if(s[i]=='\\') ans += 5*p;
            else if(s[i]=='$') ans -= p;
        }
        
        printf("%d\n",ans);
    }    
    
    return 0;
}
