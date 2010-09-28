#include <cstdio>

using namespace std;

int main(){
    char day[][10]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    int T[]={31,28,31,30,31,30,31,31,30,31,30,31};
    
    int D,M,d=1,m=0,cont=0;
    
    scanf("%d %d",&D,&M);
    M--;
    
    while(1){
        if(d==D && m==M){
            printf("%s\n",day[(cont+3)%7]);
            break;
        }
        
        if(d==T[m]){
            m++;
            d=1;
        }else d++;
        
        cont++;
    }
    
    return 0;
}
