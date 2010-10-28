#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    char N[52];
    scanf("%s",N);
    
    int L = strlen(N), ans = 0;
    
    for(int i = 0;i<L;++i)
        ans = (ans*10+N[i]-'0')%7;
    
    printf("%d\n",ans);
    
    return 0;
}
