#include <cstdio>

using namespace std;

int main(){
    int T,HH,MM;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d:%d",&HH,&MM);
        
        if(MM != 0) puts("0");
        else{
            if(HH <= 12) printf("%d\n",HH + 12);
            else printf("%d\n",HH - 12);
        }
    }
    
    return 0;
}
