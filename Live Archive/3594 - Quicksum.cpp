#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    char s[300];
    
    while(true){
        fgets(s,300,stdin);
        int L = strlen(s)-1;
        
        if(L==1 && s[0]=='#') break;
        
        int ans = 0;
        
        for(int i = 0;i<L;++i)
            if(s[i]>='A' && s[i]<='Z')
                ans += (i+1)*(s[i]-'A'+1);
        
        printf("%d\n",ans);
    }
    
    return 0;
}
