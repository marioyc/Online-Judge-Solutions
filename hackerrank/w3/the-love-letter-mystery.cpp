#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int T,L;
    char s[10001];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%s",s);
        L = strlen(s);
        int ans = 0;
        
        for(int i = 0,j = L - 1;i < j;++i,--j)
            ans += max(s[i],s[j]) - min(s[i],s[j]);
        
        printf("%d\n",ans);
    }
    
    return 0;
}
