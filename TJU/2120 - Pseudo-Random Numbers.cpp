#include <cstdio>

using namespace std;

int Z,I,M,L;

int f(int &x){
    return (Z*x+I)%M;
}

int main(){    
    int a,b,cont,caso=1;
    
    while(1){
        scanf("%d %d %d %d",&Z,&I,&M,&L);
        if(M==0) break;
        
        a=b=L;
        cont=0;
        
        do{
            a=f(a);
            b=f(b);b=f(b);
            cont++;
        }while(a!=b);
        
        a=b=L;
        for(int i=0;i<cont;i++) b=f(b);
        
        cont=0;
        
        while(a!=b){
            a=f(a);
            b=f(b);
        }
        
        b=a;
        
        do{
            b=f(b);
            cont++;
        }while(b!=a);
        
        
        printf("Case %d: %d\n",caso++,cont);
    }
    
    return 0;
}
