#include <cstdio>

using namespace std;

int main(){
    int T1,T2;
    scanf("%d %d",&T1,&T2);
    
    for(int i = 0,rej;i<10;++i){
        scanf("%d",&rej);
        T2 -= 20*rej;
    }
    
    if(T2>=T1) printf("No chance.\n");
    else printf("Dirty debug :(\n");
    
    return 0;
}
