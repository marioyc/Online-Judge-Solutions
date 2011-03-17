#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int L,tc = 1;
    char s[2001];
    
    while(true){
        scanf("%s",s);
        if(s[0]=='-') break;
        
        L = strlen(s);
        
        int ans = 0,diff = 0;
        
        for(int i = 0;i<L;++i){
            if(s[i]=='}') --diff;
            else ++diff;
            
            if(diff==-1){
                ++ans;
                diff = 1;
            }
        }
        
        ans += diff >> 1;
        
        printf("%d. %d\n",tc++,ans);
    }
    
    return 0;
}
