#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
    char s[5];
    int x,y;
    
    scanf("%s",s);
    x = atoi(s);
    
    scanf("%s",s);
    y = atoi(s);
    
    if(x % 2 == 0 || y % 2 == 1) puts("yes");
    else puts("no");
    
    return 0;
}
