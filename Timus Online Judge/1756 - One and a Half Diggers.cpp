#include <cstdio>

using namespace std;

int main(){
    int m,d1,d2;
    
    scanf("%d %d %d",&m,&d1,&d2);
    
    int m2 = (m*d1 + d2 - 1) / d2,cont = 0,total = m*d1;
    
    for(int i = 0;i < d2;++i){
        if(cont + m2 <= total){
            printf("%d ",m2);
            cont += m2;
        }else{
            printf("%d ",total - cont);
            cont = total;
        }
    }
    
    return 0;
}
