#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N;
    
    scanf("%d",&N);
    
    int a = 2,b = 10,x;
    char s[10];
    
    while(N--){
        scanf("%d %s",&x,s);
        
        if(s[0] == 'h') a = max(a,x);
        else b = min(b,x);
    }
    
    if(a >= b) puts("Inconsistent");
    else printf("%d\n",b);
    
    return 0;
}
