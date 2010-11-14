#include <cstdio>

using namespace std;

int main(){
    int n;
    
    while(scanf("%d",&n)==1){
        n &= 7;
        
        if(n==2 || n==6) puts("yes");
        else puts("no");
    }
    
    return 0;
}
