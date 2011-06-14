#include <cstdio>

using namespace std;

int main(){
    int L,ans = 0;
    char s[1001];
    
    scanf("%d %s",&L,s);
    
    for(int i = 0;i < L;++i){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            ++ans;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
