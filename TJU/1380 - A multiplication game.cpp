#include <cstdio>

using namespace std;

int main(){
    int n;
    
    while(scanf("%d",&n)==1){
        bool win = false;
        
        while(n>1){
            if(!win) n = (n+8)/9;
            else n = (n+1)/2;
            win = !win;
        }
        
        if(win) puts("Stan wins.");
        else puts("Ollie wins.");
    }
    
    return 0;
}
