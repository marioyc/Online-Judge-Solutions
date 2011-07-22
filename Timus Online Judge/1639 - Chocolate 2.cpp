#include <cstdio>

using namespace std;

int main(){
    int m,n;
    
    scanf("%d %d",&m,&n);
    
    if(m % 2 == 1 && n % 2 == 1) puts("[second]=:]");
    else puts("[:=[first]");
    
    return 0;
}
