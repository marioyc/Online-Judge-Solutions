#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int T;
    char s[100001];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%s",s);	

        int N = strlen(s),ans = 0,p = 1,l = 0;

        while(p<N && ans+l+1<N){
            if(s[ans+l]==s[(p+l)%N]) ++l;
            else if(s[ans+l]<s[(p+l)%N]){
                p = p+l+1;
                l = 0;
            }else{
                ans = max(ans+l+1,p);
                p = ans+1;
                l = 0;
            }
        }

        for(int i = ans;i<N;++i) putchar(s[i]);
        for(int i = 0;i<ans;++i) putchar(s[i]);
        putchar('\n');
    }
    
    return 0;
}
